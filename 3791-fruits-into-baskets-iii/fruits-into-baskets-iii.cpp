class Solution {
public:
    int n;
    vector<int> tree;
    void build(vector<int> &arr, int node, int s, int e){
        if(s == e) {
            tree[node] = arr[s];
            return;
        }
        int mid = s + (e-s)/2;
        build(arr, 2*node+1, s, mid);
        build(arr, 2*node+2, mid+1, e);
        tree[node] = max(tree[2*node+1], tree[2*node+2]);
    }
    int query(int node, int s, int e, int l, int r){    
        if(r < s || e < l) return INT_MIN;
        if(l <= s && e <= r) return tree[node];
        int mid = s + (e-s)/2;
        return max(query(2*node+1, s, mid, l, r), query(2*node+2, mid+1, e, l, r));
    }
    void update(int node, int s, int e, int pos, int val){
        if (s == e) {
            tree[node] = val;
            return;
        }
        int mid = (s + e) >> 1;
        if (pos <= mid) {
            update(2*node+1, s, mid, pos, val);
        } else {
            update(2*node+2, mid + 1, e, pos, val);
        }
        tree[node] = max(tree[2*node+1], tree[2*node+2]);
    }
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int size = fruits.size();
        this->n = size;
        tree.resize(4*n);
        int res = 0;

        build(baskets, 0, 0, size-1);      
        for(int i=0; i<size; i++){
            int target = fruits[i];
            int l = 0;
            int r = size-1;
            int ans = -1;
            while(l <= r){
                int mid = l + (r-l)/2;
                if(query(0, 0, n-1, 0, mid) >= target){
                    ans = mid;
                    r = mid-1;
                }
                else{
                    l = mid+1;
                }
            }
            if(ans == -1){
                res++;
            } else{
                update(0, 0, size-1, ans, INT_MIN);
            }
        }
        return res;
    }
};