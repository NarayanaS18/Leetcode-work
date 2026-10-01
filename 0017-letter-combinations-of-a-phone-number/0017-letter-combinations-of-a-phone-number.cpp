class Solution {
public:
    void f(string digit, string curStr, int i, vector<string>& ans, unordered_map<char, string> digitToChar){
        if(curStr.length() == digit.length()){
            ans.push_back(curStr);
            return;
        }

        for(auto c : digitToChar[digit[i]]){
            f(digit, curStr+c, i+1, ans, digitToChar);
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        vector<string> ans;
        string curStr = "";

        unordered_map<char, string> digitToChar = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8',"tuv"},
            {'9', "wxyz"}
        };

        f(digits, curStr, 0, ans, digitToChar);
        return ans;
    }
};