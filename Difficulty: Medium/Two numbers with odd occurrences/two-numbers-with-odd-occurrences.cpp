//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//User function Template for C++
class Solution{
    public:
    vector<long long int> twoOddNum(long long int Arr[], long long int N)  
    {
        // code here
        long long int inter = 0;
        
        for (long long int i = 0; i < N; i++){
            inter = inter ^ Arr[i];
        }
        
        long long int rightMostSetBit = (inter & (inter - 1)) ^ inter;
        long long int a = 0;
        long long int b = 0;
        
        for (long long int i = 0; i < N; i++){
            if ((Arr[i] & rightMostSetBit) != 0){
                a = a ^ Arr[i];
            } else {
                b = b ^ Arr[i];
            }
        }
        
        
        vector<long long int> ans; 
        ans.push_back(max(a,b));
        ans.push_back(min(a,b));
        
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        long long int Arr[N];
        for(long int i = 0;i < N;i++)
        cin>>Arr[i];
        Solution ob;
        vector<long long int>ans=ob.twoOddNum(Arr,N);
        for(long long int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends