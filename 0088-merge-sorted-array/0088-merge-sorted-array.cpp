class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) { 
        vector<int> temp(m+n, 0);
        int i = 0,j = 0, idx = 0;
        while(i < m && j < n){
            if(nums1[i] <= nums2[j]){
                temp[idx] = nums1[i];
                idx++;
                i++;
            }
            else{
                temp[idx] = nums2[j];
                idx++;
                j++;
            }
        }

        while(i < m){
            temp[idx] = nums1[i];
            idx++; i++;
        }
        while(j < n){
            temp[idx] = nums2[j];
            idx++; j++;
        }
        for(int i=0; i<temp.size(); i++){
            nums1[i] = temp[i];
        }
    }
};