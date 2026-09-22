class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        vector<vector<int>> ans;
        int nst = newInterval[0], nend = newInterval[1];
        int i = 0;

        //left part which do not overlap with the new interval
        while(i < n && intervals[i][1] < nst){
            ans.push_back({intervals[i][0], intervals[i][1]});
            i++;
        }
        
        //middle part which is overlapping with the new interval
        while(i < n && intervals[i][0] <= nend){
            nst = min(nst, intervals[i][0]);
            nend = max(nend, intervals[i][1]);
            i++;
        }
        ans.push_back({nst, nend});

        //last part
        while(i < n){
            ans.push_back({intervals[i][0], intervals[i][1]});
            i++;
        }
        return ans;
    }
};