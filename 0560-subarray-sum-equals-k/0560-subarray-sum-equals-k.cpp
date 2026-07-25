class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefixSum(n);
        prefixSum[0] = nums[0];

        for(int i=1; i<n; i++){
            prefixSum[i] = prefixSum[i-1] + nums[i];
        }
        unordered_map<int, int> mp;
        int cnt = 0;
        for(int i=0; i<n; i++){
            if(prefixSum[i] == k){
                cnt++;
            }
            int val = prefixSum[i] - k;
            if(mp.find(val) != mp.end()){
                cnt += mp[val];
            }
            else if(mp.find(val) == mp.end()){
                mp[val] = i;
            }
            mp[prefixSum[i]]++;
        }
        return cnt;
    }
};