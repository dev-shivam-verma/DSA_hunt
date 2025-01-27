class Solution {
public:
    void mentionOnline(vector<int> &counts,vector<int>& offList, int time ){
        int n = counts.size();
        for (int i = 0; i < n; i++){
            if (offList[i] == -1 || time >= offList[i] + 60 ) {
                counts[i]++;
            }
        }
    }

    void mentionWithId(vector<int> &counts, string ids){
        int n = ids.length();

        for (int i = 0; i < n; i++){
            if (isdigit(ids[i])){
                int count = 0;

                while (isdigit(ids[i + count]) && i + count < n){
                    count++;
                }

                string s = ids.substr(i, count);
                int id = stoi(s);
                counts[id]++;

                i += count;
            }
        }
    }

    static bool comp(vector<string>& e1, vector<string>& e2){
        int t1 = stoi(e1[1]);
        int t2 = stoi(e2[1]);
        if (t1 == t2){
            return e1[0] == "OFFLINE";
        }
        return  t1 < t2;
    }

    vector<int> countMentions(int n, vector<vector<string>>& events) {
        vector<int> offList(n, -1);
        vector<int> counts(n, 0);
        string MESSAGE = "MESSAGE";
        string OFFLINE = "OFFLINE";

        //sorting events
        sort(events.begin(), events.end(), comp);

        // handeling event queue
        for (auto event: events){
            if (event[0] == OFFLINE) {
                int id = stoi(event[2]);
                int timeStp = stoi(event[1]);

                // marking user id
                offList[id] = timeStp;
            } else {
                if (event[2] == "ALL") {


                    // mention all users
                    for (int i = 0; i < n; i++) counts[i]++;
                } else if (event[2] == "HERE") {


                    // mention all online users
                    int timeStp = stoi(event[1]);
                    mentionOnline(counts, offList, timeStp);
                } else {


                    // mention users whose id in string
                    mentionWithId(counts, event[2]);
                }
            }
        }

        return counts;
    }
};