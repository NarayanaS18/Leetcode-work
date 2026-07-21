class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //  sort(nums.begin(), nums.end());
        // // for (int i = 0; i < nums.size() - 1; i++) {
        // //     if (nums[i] == nums[i + 1]) {
        // //         return nums[i];
        // //     }
        // // }
        int left = 0;
        int right = nums.size();
        vector<int> check(nums.size(), 0); 
        for (int i = 0; i < right; i++) {
            check[nums[i]]++;
        }
        int a = 0;
        for (int i = 0; i < check.size(); i++) {
            if (check[i] > 1) {
                a = i;
            }
        }

        return a;
    }
};