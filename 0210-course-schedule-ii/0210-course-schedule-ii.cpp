class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int V = numCourses;
        vector<vector<int>> adjLs(V);
        for(int i=0; i<prerequisites.size(); i++){
            int u = prerequisites[i][0], v = prerequisites[i][1];
            adjLs[v].push_back(u);
        }
        vector<int> indegree(V, 0);
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

        vector<int> topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for(int it : adjLs[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        if(topo.size() == V) return topo;

        return {};
    }
};