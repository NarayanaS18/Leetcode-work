class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> reverseGraph(n);
        vector<int> indegree(n, 0);
        queue<int> q;

        for(int i=0; i<n; i++){
            for(int it : graph[i]){
                reverseGraph[it].push_back(i);
            }
            indegree[i] = graph[i].size();

            if(indegree[i] == 0){
                q.push(i);
            }
        }

        vector<int> ans;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for(int it : reverseGraph[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};