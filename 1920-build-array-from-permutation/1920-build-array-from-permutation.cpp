class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp(n, -1);
        for(int i=0; i<n; i++){
            temp[i] = nums[nums[i]];
        }
        return temp;
    }
};