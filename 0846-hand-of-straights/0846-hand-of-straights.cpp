class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;
        unordered_map<int,int> hash;
        priority_queue<int> maxHeap;
        list<int> queue;

        for (int i: hand) {
            if (hash.find(i) == hash.end()){
                hash[i] = 1;
                maxHeap.push(i);
            } else {
                hash[i]++;
            }
        }

        int prev = -1;
        int readyToGroup = groupSize;
        while (!maxHeap.empty() || !queue.empty()){
            if (readyToGroup == groupSize){
                while (!queue.empty()) {
                    maxHeap.push(queue.front());
                    queue.pop_front();
                }
            }

            if (prev == -1 || prev - 1 == maxHeap.top()){
                int element = maxHeap.top();
                maxHeap.pop();
                prev = element;
                readyToGroup--;

                if (hash[element] > 1) {
                    hash[element]--;
                    queue.push_back(element);
                } 
            } else return false;

            if (readyToGroup == 0){
                readyToGroup = groupSize;
                prev = -1;
            }
        }

        return readyToGroup == groupSize;
    }
};