class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int V = numCourses, n = prerequisites.size();
        vector<vector<int>> adjLs(V);
        for(int i=0; i<prerequisites.size(); i++){
            int u = prerequisites[i][0], v = prerequisites[i][1];
            adjLs[u].push_back(v);
        }
        vector<int> indegree(V, 0);
        for(int i=0; i<V; i++){
            for(auto it : adjLs[i]){
                indegree[it]++;
            }
        }

        queue<int> q;
        for(int i=0; i<V; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        int cnt = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            cnt++;

            for(auto it : adjLs[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }

        return cnt == V ? true : false;
    }
};