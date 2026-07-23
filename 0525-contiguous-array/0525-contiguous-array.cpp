class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp(2*n + 1, INT_MIN);
        int maxlen = 0, sum = 0;
        temp[n] = -1;
        for(int i=0; i<n; i++){
            sum += (nums[i] == 0) ? -1 : 1;
            if(temp[sum + n] >= -1){
                maxlen = max(maxlen, i - temp[sum+n]);
            }
            else{
                temp[sum+n] = i;
            }
        }
        return maxlen;
    }
};