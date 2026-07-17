class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> digitRange;
        for(int i=0; i<n; i++){
            int bin = nums[i];
            int small = INT_MAX, large = INT_MIN;
            while(bin > 0){
                int rem = bin % 10;
                large = max(large, rem);
                small = min(small, rem);
                bin = bin/10;
            }
            int range = large-small;
            digitRange.push_back({i, range});
        }

        int sum = 0, m = digitRange.size(), maxRange = 0;
        for(int i=0; i<m; i++){
            maxRange = max(maxRange, digitRange[i].second);
        }
        for(int i=0; i<m; i++){
            if(maxRange == digitRange[i].second){
                sum += nums[i];
            }
        }
        return sum;
    }
};