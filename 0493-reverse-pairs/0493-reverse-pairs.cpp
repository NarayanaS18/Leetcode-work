class Solution {
public:

    void merge(vector<int>& nums, int low, int mid, int high){
        int i = low, j = mid+1;
        vector<int> temp;

        while(i <= mid && j <= high){
            if(nums[i] <= nums[j]){
                temp.push_back(nums[i++]);
            }
            else{
                temp.push_back(nums[j++]);
            }
        }
        while(i <= mid){
            temp.push_back(nums[i++]);
        }
        while(j <= high){
            temp.push_back(nums[j++]);
        }

        for(int i=low; i<=high; i++){
            nums[i] = temp[i-low];
        }
    }

    int countInversions(vector<int>& nums, int low, int mid, int high){
        int j = mid+1, cnt = 0;
        for(int i=low; i<=mid; i++){
            while(j <= high && (long long)nums[i] > 2LL*nums[j]) j++;
            
            cnt += (j - (mid + 1));
        }        
        return cnt;
    }

    int mS(vector<int>& nums, int low, int high){
        int cnt = 0;
        if(low >= high) return cnt;
        int mid = (low+high)/2;

        cnt += mS(nums, low, mid);
        cnt += mS(nums, mid+1, high);
        cnt += countInversions(nums, low, mid, high);
        merge(nums, low, mid, high);
        return cnt;
    }

    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return mS(nums, 0, n-1);;
    }
};