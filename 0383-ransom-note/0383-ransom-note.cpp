class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int m = ransomNote.length(), n = magazine.length();
        sort(ransomNote.begin(), ransomNote.end());
        sort(magazine.begin(), magazine.end());
        if(m == 1 && n == 1){
            return ransomNote == magazine;
        }
        if(ransomNote.empty() || magazine.empty()) return false;

        int i = 0, j = 0;
        string temp = "";
        while(i < m && j < n){
            if(ransomNote[i] == magazine[j]){
                temp += ransomNote[i];
                i++; j++;
            }
            else{
                j++;
            }
        }
        return temp == ransomNote;
    }
};