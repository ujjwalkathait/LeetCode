class Solution:
    def minBitwiseArray(self, nums: List[int]) -> List[int]:
        res = []
        for num in nums:
            ans = -1
            for j in range(1, num):
                if (j | (j+1)) == num:
                    ans = j
                    break
            res.append(ans)
        return res