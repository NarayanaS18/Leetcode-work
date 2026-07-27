class Solution {
public:

    bool isdigit(char ch){
        if(ch >= '0' && ch <= '9') return true;
        return false;
    }

    int myAtoi(string s) {
        int n = s.length();
        int i = 0, sign = 1;
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
        while(i < n && s[i] == '0'){
            i++;
        }
        while(i < n && isdigit(s[i])){
            int d = s[i]-'0';
            ans = ans*10 + d;

            if(sign == -1 && -ans < INT_MIN) return INT_MIN;
            if(sign == 1 && ans > INT_MAX) return INT_MAX;

            i++;
        }
            
        return ans*sign;
    }
};