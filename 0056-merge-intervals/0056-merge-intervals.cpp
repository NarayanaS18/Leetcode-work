class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;

        for(int i=0; i<n; i++){
            if(ans.empty() || ans[ans.size()-1][1] < intervals[i][0]){
                ans.push_back(intervals[i]);
            }
            else{
                ans[ans.size()-1][1] = max(ans[ans.size()-1][1], intervals[i][1]);
            }
        }
        return ans;
    }
};