class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        int mini = n/3 + 1;
        int cnt1 = 0, cnt2 = 0;
        int val1 = 0, val2 = 0;
        for(int i=0; i<n; i++){
            if(cnt1 == 0 && nums[i] != val2){
                cnt1 = 1;
                val1 = nums[i];
            }
            else if(cnt2 == 0 && nums[i] != val1){
                cnt2 = 1;
                val2 = nums[i];
            }
            else if(nums[i] == val1) cnt1++;
            else if(nums[i] == val2) cnt2++;
            else{
                cnt1--;
                cnt2--;
            }
        }

        cnt1 = 0, cnt2 = 0;
        for(int i=0; i<n; i++){
            if(val1 == nums[i]) cnt1++;
            if(val2 == nums[i]) cnt2++;
        }
        if(cnt1 >= mini) ans.push_back(val1);
        if(cnt2 >= mini && val1 != val2) ans.push_back(val2);
        sort(ans.begin(), ans.end());
        return ans;
    }
};