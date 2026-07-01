class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int m = a.length(), n = b.length();
        string repeated = "";
        int count = 0;
        while(repeated.size() < n){
            repeated += a;
            count++;
        }

        if(repeated.find(b) != string::npos){
            return count;
        }
        repeated += a;
        count++;

        if(repeated.find(b) != string::npos)
            return count;
        
        return -1;
    }
};