class Solution {
public:
    int n;
    vector<int> tree;
    void buildTree(int i, int l, int r, vector<int> &arr){
        if(l == r){
            tree[i] = l;
            return;
        }
        int mid = l + (r-l)/2;
        buildTree(2*i+1, l, mid, arr);
        buildTree(2*i+2, mid+1, r, arr);
        if(arr[tree[2*i+1]] > arr[tree[2*i+2]]){
            tree[i] = tree[2*i+1];
        }
        else{
            tree[i] = tree[2*i+2];
        }
    }
    int queryMaxIndex(int i, int start, int end, int l, int r, vector<int> &arr){
        if(r < start || end < l) return -1;
        if(l <= start && end <= r) return tree[i];

        int mid = start + (end - start) / 2;
        int left = queryMaxIndex(2*i + 1, start, mid, l , r, arr);
        int right = queryMaxIndex(2*i + 2, mid+1, end, l, r, arr);
        
        if (left == -1) return right;
        if (right == -1) return left;
        return (arr[left] >= arr[right]) ? left : right;
    }
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
       n = heights.size();
       tree.resize(n * 4);

       buildTree(0 , 0, n-1, heights); 

       int qsize = queries.size();
       vector<int> result;

       for(int i=0; i<qsize; i++){
            int maxi = max(queries[i][0], queries[i][1]);
            int mini = min(queries[i][0], queries[i][1]);

            if(maxi == mini){
                result.push_back(mini);
                continue;
            }
            if(heights[maxi] > heights[mini]){
                result.push_back(maxi);
                continue;
            }

            int l = max(queries[i][0],queries[i][1]);
            int r = heights.size() - 1;
            int ans = -1;

            int mid = l + (r-l) / 2;
            while(l <= r){
                int val = queryMaxIndex(0, 0, n-1, l , mid, heights);
                if(heights[val] > heights[queries[i][0]] && heights[val] > heights[queries[i][1]]){
                    ans = val;
                    r = mid - 1;
                }
                else{
                    l = mid + 1;
                }
                mid = l + (r-l) / 2;
            }
            result.push_back(ans);
       }

       return result;
    }
};