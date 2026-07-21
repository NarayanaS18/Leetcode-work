class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size();
        int node = n+1;
        vector<vector<int>> adjLs(node+1);
        for(int i=0; i<n; i++){
            int u = edges[i][0], v = edges[i][1];
            adjLs[u].push_back(v);
            adjLs[v].push_back(u);
        }

        for(int i=1; i<adjLs.size(); i++){
            if(adjLs[i].size() > 1){
               return i;
            }
        }
        return -1;
    }
};