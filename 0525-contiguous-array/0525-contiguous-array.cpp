class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int maxlen = 0, sum = 0;
        unordered_map<int, int> mp;
        mp[0] = -1; //this will handle subarray that starts from 0
        //prefix sum, index
        // 0 -> -1 and 1 -> +1
        for(int i=0; i<n; i++){
            sum += (nums[i] == 0) ? -1 : 1;
            if(mp.find(sum) != mp.end()){
                maxlen = max(maxlen, i - mp[sum]);
            }
            else{
                mp[sum] = i;
            }
        }
        return maxlen;
    }
};