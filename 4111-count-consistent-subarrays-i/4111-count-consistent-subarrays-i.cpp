class Solution {
public:
    int countConsistent(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for(int i=0; i<n; i++){
            int mini = nums[i], op = nums[i];
            for(int j=i; j<n; j++){
                mini = min(mini, nums[j]);
                op &= nums[j];
                if(op == mini){
                    cnt++;
                }
            }

        }
        return cnt;
    }
};