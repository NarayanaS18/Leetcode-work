class Solution {
public:

    void f(vector<int>& nums, int idx, vector<vector<int>>& ans, vector<int>& arr){
        if(idx == nums.size()){
            ans.push_back(arr);
            return;
        }

        //include
        arr.push_back(nums[idx]);
        f(nums, idx+1, ans, arr);

        //exclude
        arr.pop_back();
        f(nums, idx+1, ans, arr);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> arr;
        f(nums, 0, ans, arr);

        return ans;
    }
};