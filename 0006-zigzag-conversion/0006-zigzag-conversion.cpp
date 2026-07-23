class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.length(), m = numRows;
        if(m == 1 || m > n) return s;

        int curRow = 0, direction = 0;
        vector<string> rows(m);
        for(char c : s){
            rows[curRow] += c;

            if(curRow == 0) direction = 1;
            else if(curRow == m-1) direction = -1;

            curRow += direction;
        }  

        string ans;
        for(const string& r : rows){
            ans += r;
        }

        return ans;
    }
};