class Solution:
    def maxSubArray(self, nums: list[int]) -> int:

        max_sum = nums[0]
        sum = 0

        for x in nums:
            sum += x
            max_sum = max(max_sum, sum)

            if sum < 0:
                sum = 0
        
        return max_sum