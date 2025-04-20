class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
        unordered_map<int, int> hash; 

        for (int i: nums){
            if (hash.find(i) == hash.end()) hash[i] = 1;
            else hash[i]++;
        }

        for (auto i: hash){
            minHeap.push({i.second, i.first});

            while (minHeap.size() > k) minHeap.pop();
        }


        vector<int> ans;
        while (!minHeap.empty()) {
            ans.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return ans;
    }
};