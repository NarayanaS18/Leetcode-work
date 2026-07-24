class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.length(), m = numRows;
        if(m == 1 || m > n) return s;
        vector<string> rows(m);
        int curRow = 0, direction = 0;
        for(char c : s){
            rows[curRow] += c;

            if(curRow == 0) direction = 1;
            else if(curRow == m-1) direction = -1;

            curRow += direction;
        }

        string ans = "";
        for(string &s : rows){
            ans += s;
        }
        return ans;
    }
};