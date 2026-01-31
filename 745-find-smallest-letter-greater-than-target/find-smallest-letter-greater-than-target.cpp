class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int l = 0, r = letters.size() - 1;
        int mid = l + (r-l) / 2;

        if(target >= letters[r]){
            return letters[0];
        }
        while(l <= r){
            if(letters[mid] > target){
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
            mid = l + (r-l) / 2;
        }
        return letters[l];
    }
};