class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> temp(m+n, 0);
        int i=0, j=0;
        int idx = 0;
        while(i < m && j < n){
            if(nums1[i] <= nums2[j]){
                temp[idx] = nums1[i];
                idx++;
                i++;
            }
            else if(nums1[i] > nums2[j]){
                temp[idx] = nums2[j];
                idx++;
                j++;
            }
        }
        if(j < n && i == m){
            while(j < n){
                temp[idx] = nums2[j];
                idx++;j++;
            }
        }
        if(i < m && j == n){
            while(i<m){
                temp[idx] = nums1[i];
                idx++;i++;
            }
        }
        for(int i=0; i<temp.size(); i++){
            nums1[i] = temp[i];
        }
    }
};