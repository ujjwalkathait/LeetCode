class Solution {
public:
    string addBinary(string a, string b) {
        int i, j, n=a.size(), m=b.size();
        string ans = "";
        int sum = 0;
        for(i=n-1, j=m-1; i>=0 && j>=0; i--,j--){
            sum += (a[i]-'0') + (b[j]-'0');
            ans.push_back((sum%2)+'0');
            sum /= 2;
        }
        while(i>=0){
            sum += (a[i]-'0');
            ans.push_back((sum%2)+'0');
            sum /= 2;
            i--;
        }
        while(j>=0){
            sum += (b[j]-'0');
            ans.push_back((sum%2)+'0');
            sum /= 2;
            j--;
        }
        if(sum != 0){
            ans.push_back((sum%2)+'0');
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};