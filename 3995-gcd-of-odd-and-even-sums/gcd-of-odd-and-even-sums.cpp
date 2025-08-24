class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        return n * gcd(n, n+1);
    }
};