//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
  
    bool dirIsValid(vector<vector<int>>& maze, pair<int,int> ratPos, int dir){
        int n = maze.size();
        
        if (dir == 0){
             if (ratPos.first == 0) return false;
             if (maze[ratPos.first - 1][ratPos.second] == 0) return false;
        }
        if (dir == 1){
            if (ratPos.first == n-1) return false;
            if (maze[ratPos.first + 1][ratPos.second] == 0) return false;
        }
        if (dir == 2){
            if (ratPos.second == 0) return false;
            if (maze[ratPos.first][ratPos.second - 1] == 0) return false;
        }
        if (dir == 3){
            if (ratPos.second == n - 1) return false;
            if (maze[ratPos.first][ratPos.second + 1] == 0) return false;
        }
        
        return true;
    }
    
    void findWaysOut(vector<vector<int>>& maze, pair<int,int> ratPos, string path, vector<string>& ans){
        
        int n = maze.size();
        if (ratPos.first == n-1 && ratPos.second == n-1){
            ans.push_back(path);
            return;
        }
        
        // mark current position as visited
        maze[ratPos.first][ratPos.second] = 0;
        
        // visiting valid direction- using code 0,1,2,3 for UP,DOWN,LEFT,RIGHT respectively
        for (int i = 0; i < 4; i++){
            if (dirIsValid(maze, ratPos, i)){
                
                switch (i) {
                    case 0: ratPos.first--; break;
                    case 1: ratPos.first++; break;
                    case 2: ratPos.second--; break;
                    case 3: ratPos.second++; break;
                }
                
                findWaysOut(maze, ratPos, path + "UDLR"[i], ans);
                
                // reversing rat position 
                switch (i) {
                    case 0: ratPos.first++; break;
                    case 1: ratPos.first--; break;
                    case 2: ratPos.second++; break;
                    case 3: ratPos.second--; break;
                }
            }
        }

        
        // unmark current position on backtracking
        maze[ratPos.first][ratPos.second] = 1;
        
        return;
    }
    
    
    vector<string> findPath(vector<vector<int>> &mat) {
        // code here
        vector<string> ans;
        pair<int,int> initialPos(0,0);
        findWaysOut(mat, initialPos, "", ans);
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        vector<vector<int>> mat;
        string innerArray;
        bool isInsideArray = false;

        for (char c : input) {
            if (c == '[') {
                if (isInsideArray) {
                    innerArray.clear();
                }
                isInsideArray = true;
            } else if (c == ']') {
                if (isInsideArray && !innerArray.empty()) {
                    vector<int> row;
                    stringstream ss(innerArray);
                    int num;

                    while (ss >> num) {
                        row.push_back(num);
                        if (ss.peek() == ',')
                            ss.ignore();
                        while (isspace(ss.peek()))
                            ss.ignore();
                    }

                    mat.push_back(row);
                    innerArray.clear();
                }
                isInsideArray = false;
            } else if (isInsideArray) {
                if (!isspace(c)) {
                    innerArray += c;
                }
            }
        }

        Solution obj;
        vector<string> result = obj.findPath(mat);
        sort(result.begin(), result.end());

        if (result.empty())
            cout << "[]";
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends