class Solution {
public:

    void dfs(int node, vector<vector<int>>& rooms, vector<int>& vis){
        int n = rooms.size();

        vis[node] = 1;
        for(auto it : rooms[node]){
            if(!vis[it]){
                dfs(it, rooms, vis);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> vis(n, 0);
        queue<int> q;
        q.push(0);
        vis[0] = 1;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto it : rooms[node]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }

        for(int i=0; i<vis.size(); i++){
            if(vis[i] != 1){
                return false;
            }
        }
        return true;
    }
};