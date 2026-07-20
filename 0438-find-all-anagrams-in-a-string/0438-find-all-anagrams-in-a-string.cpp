class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int m = s.length(), n = p.length();
        if(m < n) return {};
        vector<int> pCount(26, 0), window(26, 0);
        vector<int> ans;

        for(int i=0; i<n; i++){
            pCount[p[i]-'a']++;
            window[s[i]-'a']++;
        }
        if(pCount == window) ans.push_back(0);

        int left = 0;
        for(int i=n; i<m; i++){
            window[s[i]-'a']++;
            window[s[left]-'a']--;
            left++;

            if(pCount == window) ans.push_back(left);
        }
        return ans;
    }
};