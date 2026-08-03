class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> m;
        for(int i=0; i<n; i++){
            int val = nums[i];
            if(m.find(val) != m.end()){
                return val;
            }
            else{
                m[val] = i;
            }
        }
        return -1;
    }
};