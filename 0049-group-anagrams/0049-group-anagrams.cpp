class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string, vector<string>> mp;

        for(string& s: strs){
            vector<int> count(26, 0);

            for(char c : s){
                count[c -'a']++;
            }

            string key;
            for(int num : count){
                key += to_string(num) + "#";
            }
            mp[key].push_back(s);
        }

        vector<vector<string>> ans;
        for(auto& it : mp){
            ans.push_back(move(it.second));
        }
        return ans;
    }
};