class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int cnt = 0;
        for(int i=low; i<=high; i++){
            string s = to_string(i);
            if(s.size()%2 == 0){
                int mid = s.size()/2;
                int sum = 0;
                for(int j=0; j<mid; j++){
                    sum += s[j];
                }
                for(int j=mid; j<s.size(); j++){
                    sum -= s[j];
                }
                if(sum == 0){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};