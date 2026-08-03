class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        set<int> s;
        for(int i=0; i<n; i++){
            int val = nums[i];
            if(s.find(val) != s.end()){
                return val;
            }
            else{
                s.insert(val);
            }
        }
        return -1;
    }
};