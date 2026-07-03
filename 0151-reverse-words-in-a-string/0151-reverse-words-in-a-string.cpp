class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        int i = n-1;
        string ans = "";
        while(i >= 0){
            //ignore the spaces at the end
            while(i >= 0 && s[i] == ' '){
                i--;
            }
            //if it reached beginning end the loop
            if(i < 0) break;

            int right = i; //mark the ending of the word

            //this loop will run till ending to beginning of the word
            while(i >= 0 && s[i] != ' '){
                i--;
            }
            //if ans is not empty and contains word this will add space between words
            if(!ans.empty()){
                ans += ' '; 
            }
            //i would be space before word so i+1 and right will be at last letter of word so right-i will give word length
            ans += s.substr(i+1, right-i);
        }
        return ans;
    }
};