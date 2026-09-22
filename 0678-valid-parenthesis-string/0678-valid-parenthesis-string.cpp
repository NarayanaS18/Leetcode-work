class Solution {
public:
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
        return (mincnt == 0);
    }
};