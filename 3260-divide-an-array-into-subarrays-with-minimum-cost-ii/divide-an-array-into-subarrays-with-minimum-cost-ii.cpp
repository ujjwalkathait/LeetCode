class Solution {
public:
    typedef long long ll;
    typedef pair<ll, ll> pp;
    ll minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();
        set<pp> kMin, rem;
        ll sum = 0, ans = LLONG_MAX;
        int i = 1;
        while(i <= dist){
            kMin.insert({nums[i], i});
            sum += nums[i];
            if(kMin.size() > k-1) {
                pp temp = *kMin.rbegin(); // largest element
                sum -= temp.first;
                rem.insert(temp);
                kMin.erase(temp);
            }
            i++;
        }

        while(i < n){
            kMin.insert({nums[i], i});
            sum += nums[i];

            if(kMin.size() > k-1) {
                pp temp = *kMin.rbegin(); // largest element
                sum -= temp.first;
                rem.insert(temp);
                kMin.erase(temp);
            }

            ans = min(ans, sum);

            pp remove = {nums[i-dist], i-dist};
            if(kMin.count(remove)){
                kMin.erase(remove);
                sum -= remove.first;

                if(!rem.empty()){
                    pp temp = *rem.begin(); // smallest element
                    kMin.insert(temp);
                    sum += temp.first;
                    rem.erase(temp);
                }
            }
            else{
                rem.erase(remove);
            }
            i++;
        }

        return nums[0] + ans;
    }
};