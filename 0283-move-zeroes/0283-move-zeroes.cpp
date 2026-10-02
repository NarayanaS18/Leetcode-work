class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        for(int i=0; i<n; i++){
            if(nums[i] != 0){
                temp.push_back(nums[i]);
            }
        }
        int m = temp.size();
        for(int i=0; i<n; i++){
            if(i < m){
                nums[i] = temp[i];
            }
            else nums[i] = 0;
        }
    }
};