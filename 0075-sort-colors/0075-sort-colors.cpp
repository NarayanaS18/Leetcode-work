class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int c0 = 0, c1 = 0, c2 = 0;
        for(int i=0; i<n; i++){
            if(nums[i] == 0) c0++;
            else if(nums[i] == 1) c1++;
            else c2++;
        }

        // for(int i=0; i<c0; i++){
        //     nums[i] = 0;
        // }
        int m = c0+c1;
        // for(int i=c0; i<m; i++){
        //     nums[i] = 1;
        // }
        // for(int i=m; i<n; i++){
        //     nums[i] = 2;
        // }

        for(int i=0; i<n; i++){
            if(i >= 0 && i < c0){
                nums[i] = 0;
            }
            else if(i >= c0 && i < m){
                nums[i] = 1;
            }
            else{
                nums[i] = 2;
            }
        }
    }
};