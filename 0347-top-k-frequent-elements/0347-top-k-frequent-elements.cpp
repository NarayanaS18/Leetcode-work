class Solution {
public:

    static bool CompSecond(const pair<int, int>& a, const pair<int, int>& b){
        return a.second > b.second;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;

        for(int i=0; i<n; i++){
            mp[nums[i]]++;
        }

        vector<pair<int, int>> temp;
        for(const auto& [num, freq] : mp){
            temp.push_back({num, freq});
        }
        sort(temp.begin(), temp.end(), CompSecond);

        vector<int> ans;
        for(int i=0; i<k; i++){
            ans.push_back(temp[i].first);
        }
        return ans;
    }
};