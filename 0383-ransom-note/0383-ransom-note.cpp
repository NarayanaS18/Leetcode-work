class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int m = ransomNote.size(), n = magazine.size();
        vector<int> freq(26, 0);
        for(int i=0; i<n; i++){
            freq[magazine[i]-'a']++;
        }

        for(int j=0; j<m; j++){
            freq[ransomNote[j]-'a']--;
            if(freq[ransomNote[j]-'a'] < 0) return false;
        }
        return true;
    }
};