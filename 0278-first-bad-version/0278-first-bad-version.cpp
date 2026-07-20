// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int st = 1, end = n;
        int minBad = INT_MAX;
        while(st <= end){
            int mid = st + (end-st)/2;
            if(isBadVersion(mid)){
                minBad = min(minBad, mid);
                end = mid-1;
            }
            else if(!isBadVersion(mid)){
                st = mid+1;
            }
        }
        return minBad;
    }
};