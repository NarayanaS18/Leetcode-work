class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.length(), m = t.length();
        if(n != m) return false;

        vector<int> hash(26, 0);

        for(int i=0; i<n; i++){
            hash[s[i]-'a']++;
            hash[t[i]-'a']--;
        }

        for(int val : hash){
            if(val != 0){
                return false;
            }
        }
        return true;
    }
};