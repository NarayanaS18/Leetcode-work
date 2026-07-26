class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string, vector<string>> m;

        for(string &it : strs){
            string key = it;
            sort(key.begin(), key.end());
            m[key].push_back(it);
        }

        vector<vector<string>> ans;
        for(auto& it: m){
            ans.push_back(it.second);
        }
        return ans;
    }
};