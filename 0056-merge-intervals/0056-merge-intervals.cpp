class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
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