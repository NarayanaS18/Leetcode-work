class Solution {
public:

    bool isdigit(char c){
        if(c >= '0' && c <= '9') return true;
        return false;
    }

    int myAtoi(string s) {
        int n = s.length(), i = 0, sign = 1;
        long long ans = 0;
        
        while(i < n && s[i] == ' '){
            i++;
        }
        if(i == n) return 0;

        if(i < n && s[i] == '+') i++;
        else if(i < n && s[i] == '-'){
            sign = -1;
            i++;
        }

        while(i < n && isdigit(s[i])){
            int dig = s[i]-'0';
            ans = ans*10 + dig;

            if(sign == -1 && -ans < INT_MIN) return INT_MIN;
            if(sign == 1 && ans > INT_MAX) return INT_MAX;
            i++;
        }

        return sign*ans;
    }
};