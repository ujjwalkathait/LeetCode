class Solution {
public:
    int countMonobit(int n) {
        if(n == 1) return 2;

        return log2(n+1) + 1;
    }
};