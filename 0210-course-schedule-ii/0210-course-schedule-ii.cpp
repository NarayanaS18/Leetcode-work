class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int V = numCourses, n = prerequisites.size();
        vector<vector<int>> adjLs(V);
        for(int i=0; i<n; i++){
            int u = prerequisites[i][0], v = prerequisites[i][1];
            adjLs[v].push_back(u);
        }
        vector<int> indegree(V);
        for(int i=0; i<V; i++){
            for(int it : adjLs[i]){
                indegree[it]++;
            }
        }
        queue<int> q;
        for(int i=0; i<V; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        vector<int> ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for(int it : adjLs[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        if(ans.size() == V) return ans;
        return {};
    }
};