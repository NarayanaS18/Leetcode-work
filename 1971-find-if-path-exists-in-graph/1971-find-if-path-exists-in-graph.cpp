class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> adjLs[n+1];
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0], v = edges[i][1];
            adjLs[u].push_back(v);
            adjLs[v].push_back(u);
            
        }

        vector<int> vis(n, 0);
        vis[source] = 1;
        queue<int> q;
        q.push(source);

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto it : adjLs[node]){
                if(!vis[it]){
                    q.push(it);
                    vis[it] = 1;
                }
            }
        }
        return vis[destination];
    }
};