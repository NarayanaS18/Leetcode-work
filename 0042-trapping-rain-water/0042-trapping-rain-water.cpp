class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> suffix(n);
        suffix[n-1] = height[n-1];

        for(int i=n-2; i>=0; i--){
            suffix[i] = max(suffix[i+1], height[i]);
        }
        int lmax = 0, rmax = 0, total = 0;
        for(int i=0; i<n; i++){
            lmax = max(lmax, height[i]);
            rmax = suffix[i];

            if(height[i] < lmax && height[i] < rmax){
                total += min(lmax, rmax) - height[i];
            }
        }
        return total;
    }
};