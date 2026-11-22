class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trustCount(n+1, 0);
        vector<int> trustByCount(n+1, 0);

        for(int i=0; i<trust.size(); i++){
            trustCount[trust[i][0]]++;
            trustByCount[trust[i][1]]++;
        }

        for(int i=1; i<=n; i++){
            if(trustCount[i] == 0 && trustByCount[i] == n-1){
                return i;
            } 
        }
        return -1;
    }
};