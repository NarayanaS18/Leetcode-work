class Solution {
public:

    bool isSame(int a[], int b[]){
        for(int i=0; i<26; i++){
            if(a[i] != b[i]) return false;
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        int m = s1.length(), n = s2.length();
        int freq[26] = {0};

        for(char c : s1){
            freq[c-'a']++;
        }
        int windSize = m;

        for(int i=0; i<n; i++){
            int windIdx = 0, idx=i;
            int windFreq[26] = {0};

            while(windIdx < windSize && idx < n){
                windFreq[s2[idx]-'a']++;
                idx++;
                windIdx++;
            }

            if(isSame(freq, windFreq)){
                return true;
            }
        }
        return false;
    }
};