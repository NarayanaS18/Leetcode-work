class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int ans = nums[0], cnt = 0, maxCnt = 0;
        for(int i=0; i<n; i++){
            if(cnt == 0){
                ans = nums[i];
            }
            if(ans == nums[i]){
                cnt++;
            }
            else{
                cnt--;
            }
        }
        return ans;
    }
};