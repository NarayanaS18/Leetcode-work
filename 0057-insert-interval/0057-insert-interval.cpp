class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        vector<vector<int>> ans;

        int i=0;
        int nst = newInterval[0], nend = newInterval[1];

        while(i < n && intervals[i][1] < nst){
            ans.push_back({intervals[i][0], intervals[i][1]});
            i++;
        }

        while(i < n && intervals[i][0] <= nend){
            nst = min(nst, intervals[i][0]);
            nend = max(nend, intervals[i][1]);
            i++;
        }
        ans.push_back({nst, nend});

        while(i < n){
            ans.push_back({intervals[i][0], intervals[i][1]});
            i++;
        }

        return ans;
    }
};