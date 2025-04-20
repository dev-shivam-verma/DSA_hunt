class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> buckets(n + 1, vector<int>());
        unordered_map<int, int> hash; 


        for (int i: nums){
            if (hash.find(i) == hash.end()) hash[i] = 1;
            else hash[i]++;
        }

        for (auto i: hash){
            buckets[i.second].push_back(i.first);
        }


        vector<int> ans;
        for (int i = n ; i > 0; i--){
            for (int j: buckets[i]){
                ans.push_back(j);
                if (ans.size() >= k) return ans;
            }
        }

        return ans;
    }
};