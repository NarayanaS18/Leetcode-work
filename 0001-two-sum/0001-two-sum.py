class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        pair_idx = {}

        for i, num in enumerate(nums):
            val = target-num
            if val in pair_idx:
                return [pair_idx[val], i]
            pair_idx[num] = i
        return [-1, -1]