class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MIN, prefix = 1, suffix = 1;
        int i = 0, j = n-1;
        while(i < n && j >= 0){
            if(prefix == 0) prefix = 1;
            if(suffix == 0) suffix = 1;
            prefix *= nums[i];
            suffix *= nums[j];
            ans = max(ans, max(prefix, suffix));
            i++;
            j--;
        }
        return ans;
    }
};