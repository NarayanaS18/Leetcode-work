class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size(), maxOnes = 0, cnt = 0;
        for(int i=0; i<n; i++){
            if(nums[i] == 1){
                cnt++;
            }
            maxOnes = max(maxOnes, cnt);
            if(nums[i] != 1){
                cnt = 0;
            }
        }
        return maxOnes;
    }
};