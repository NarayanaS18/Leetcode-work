class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> s;

        for(int i=0; i<n; i++){
            s.insert(nums[i]);
        }

        int cnt = 1, maxlen = 0;
        for(int num : s){
            if(s.find(num-1) == s.end()){
                int cur = num;
                cnt = 1;

                while(s.find(cur+1) != s.end()){
                    cnt++;
                    cur = cur+1;
                }
                maxlen = max(maxlen, cnt);
            }
        }
        return maxlen;
    }
};