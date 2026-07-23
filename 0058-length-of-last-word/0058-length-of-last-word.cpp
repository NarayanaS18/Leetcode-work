class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length();
        int i = n-1;
        string word = "";
        while(i >= 0){
            while(i >= 0 && s[i] == ' '){
                i--;
            }
            if(i < 0){
                break;
            }
            int right = i;
            while(i >= 0 && s[i] != ' '){
                i--;
            }

            if(word.empty()){
                word = s.substr(i+1, right-i);
            }
        }

        return word.length();
    }
};