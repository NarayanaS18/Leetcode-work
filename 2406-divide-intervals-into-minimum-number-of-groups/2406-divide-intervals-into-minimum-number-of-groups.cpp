class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> arrive(n, 0), departure(n, 0);

        for(int i=0; i<n; i++){
            arrive[i] = intervals[i][0];
            departure[i] = intervals[i][1];
        }

        sort(arrive.begin(), arrive.end());
        sort(departure.begin(), departure.end());

        int i = 0, j = 0;
        int cnt = 0, maxcnt = 0;
        while(i < n){
            if(arrive[i] <= departure[j]){
                cnt++;
                i++;
            }
            else{
                cnt--;
                j++;
            }

            maxcnt = max(maxcnt, cnt);
        }
        return maxcnt;
    }
};