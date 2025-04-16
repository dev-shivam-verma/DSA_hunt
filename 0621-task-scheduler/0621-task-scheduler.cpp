class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> max_heap;
        vector<int> hash(26, 0);
        list<pair<int,int>> queue;

        for(char i: tasks){
            hash[i - 'A']++;
        }
        
        for (int i: hash)
            if (i > 0) max_heap.push(i);

        
        int time = 0;
        while (!max_heap.empty() || !queue.empty()){
            time++;

            if(!max_heap.empty()){
                int freq = max_heap.top();
                max_heap.pop();

                int coolTime = time + n;
                if (freq > 1) queue.push_back({--freq, coolTime});
            }

            if (!queue.empty() && queue.front().second == time){
                max_heap.push(queue.front().first);
                queue.pop_front();
            }
        }

        return time;
    }
};