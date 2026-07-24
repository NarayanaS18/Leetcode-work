class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adjLs(n+1);

        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0], v = edges[i][1];
            adjLs[u].push_back(v);
            adjLs[v].push_back(u);
        }
        vector<int> vis(n);
        vis[source] = 1;
        queue<int> q;
        q.push(source);
        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(int it : adjLs[node]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }

        return vis[destination];
    }
};