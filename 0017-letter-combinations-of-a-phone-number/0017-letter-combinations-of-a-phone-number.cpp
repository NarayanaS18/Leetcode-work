class Solution {
public:

    void f(string digits, int i, string curStr, unordered_map<char, string> digitToChar, vector<string>& ans){
        if(curStr.length() == digits.length()){
            ans.push_back(curStr);
        }

        for(auto c : digitToChar[digits[i]]){
            f(digits, i+1, curStr+c, digitToChar, ans);
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        vector<string> ans;
        unordered_map<char, string> digitToChar = {
            {'2' , "abc"},
            {'3' , "def"},
            {'4' , "ghi"},
            {'5' , "jkl"},
            {'6' , "mno"},
            {'7' , "pqrs"},
            {'8' , "tuv"},
            {'9' , "wxyz"}
        };
        string curStr = "";
        f(digits, 0, curStr,digitToChar, ans);
        return ans;
    }
};