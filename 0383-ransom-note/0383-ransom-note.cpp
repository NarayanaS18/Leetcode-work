class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int freq[26] = {0};
        for(int c : magazine){
            freq[c-'a']++;
        }
        for(int ch : ransomNote){
            freq[ch-'a']--;
            if(freq[ch-'a'] < 0) return false;
        }
        return true;
    }
};