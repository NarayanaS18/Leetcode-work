class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> arrival(n, 0), departure(n, 0);
        
        for(int i=0; i<n; i++){
            arrival[i] = intervals[i][0];
            departure[i] = intervals[i][1];
        }
        sort(arrival.begin(), arrival.end());
        sort(departure.begin(), departure.end());
        int cnt = 0, maxcnt = 0;
        int i = 0, j = 0;
        while(i < n){
            if(arrival[i] <= departure[j]){
                cnt++;
                i++;
            }
            else{
                cnt--;
                j++;
            }
            if(cnt < 0) cnt = 0;
            maxcnt = max(maxcnt, cnt);
        }
        return maxcnt;
    }
};