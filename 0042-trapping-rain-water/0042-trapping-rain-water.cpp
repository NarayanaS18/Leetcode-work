class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int total = 0;
        vector<int> suffix(n);
        suffix[n-1] = height[n-1];

        for(int i=n-2; i>=0; i--){
            suffix[i] = max(suffix[i+1], height[i]);
        }
        int lmax = height[0];
        for(int i=0; i<n; i++){
            lmax = max(lmax, height[i]);
            int rmax = suffix[i];
            if(lmax > height[i] && rmax > height[i]){
                total += min(lmax, rmax) - height[i];
            }
        }
        return total;
    }
};