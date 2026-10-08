class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        set<int> temp;
        sort(nums.begin(), nums.end());
        int cnt = 0, ans = nums[0];

        for(int i=0; i<n; i++){
            if(ans != nums[i]){
                cnt = 0;
                ans = nums[i];
            }
            if(ans == nums[i]){
                cnt++;
            }

            if(cnt > (n/3)) temp.insert(ans);
        }
        vector<int> arr(temp.begin(), temp.end());
        return arr;
    }
};