class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.length(), m = t.length();
        if(n != m) return false;
        vector<int> hash(26, 0);

        for(int i=0; i<n; i++){
            hash[s[i]-'a']++;
        }

        for(int i=0; i<m; i++){
            hash[t[i]-'a']--;
            if(hash[t[i]-'a'] < 0) return false;
        }
        return true;
    }
};