class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<bool> indegree(n, false);

        for(auto& e : edges){
            int u = e[0];
            int v = e[1];
            indegree[v] = true;
        }
        vector<int> ans;
        for(int i=0; i<n; i++){
            if(indegree[i] == false){
                ans.push_back(i);
            }
        }
        return ans;
    }
};