class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        int i = 0;
        while(i < n){
            int st = intervals[i][0], end = intervals[i][1];

            int j = i+1;
            while(j < n && intervals[j][0] <= end){
                end = max(end, intervals[j][1]);
                j++;
            }
            ans.push_back({st, end});
            
            i = j;
        }
        return ans;
    }
};