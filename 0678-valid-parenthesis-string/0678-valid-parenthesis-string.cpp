class Solution {
public:
    // bool f(string s, int idx, int cnt, vector<vector<int>>& dp){
    //     int n = s.length();
    //     if(cnt < 0) return false;
    //     if(idx == n) return (cnt == 0);
    //     if(dp[idx][cnt] != -1) return dp[idx][cnt];
    //     if(s[idx] == '('){
    //         return dp[idx][cnt] = f(s, idx+1, cnt+1, dp);
    //     }
    //     if(s[idx] == ')'){
    //         return dp[idx][cnt] = f(s, idx+1, cnt-1, dp);
    //     }

    //     return dp[idx][cnt] = f(s, idx+1, cnt+1, dp) || f(s, idx+1, cnt-1, dp) || f(s, idx+1, cnt, dp);
    // }

    bool checkValidString(string s) {
        int n = s.length();
        int mincnt = 0, maxcnt = 0;

        for(int i=0; i<n; i++){
            if(s[i] == '('){
                mincnt++;
                maxcnt++;
            }
            else if(s[i] == ')'){
                mincnt--;
                maxcnt--;
            }
            else{
                mincnt--;
                maxcnt++;
            }

            if(mincnt < 0) mincnt = 0;
            if(maxcnt < 0) return false;
        }
        return mincnt == 0;
    }
};