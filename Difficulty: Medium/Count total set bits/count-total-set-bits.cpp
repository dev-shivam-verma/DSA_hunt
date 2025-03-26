//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//User function Template for C++

class Solution{
    public:
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
    int countSetBits(int n)
    {
        // Your logic here
        
        int count = 0;
        
        int onesInPattern = 1;
        int patternSize = 2;
        int counter = n;
        while (counter > 0){
            count += (n + 1) / patternSize * onesInPattern;
            
            int r = (n + 1) % patternSize;
            if (r > (patternSize / 2)){
                count += r - (patternSize/2);
            }
            
            onesInPattern *= 2;
            patternSize *= 2;
            counter = counter >> 1;
        }
        
        return count;
    }
};



//{ Driver Code Starts.

// Driver code
int main()
{
	 int t;
	 cin>>t;// input testcases
	 while(t--) //while testcases exist
	 {
	       int n;
	       cin>>n; //input n
	       Solution ob;
	       cout << ob.countSetBits(n) << endl;// print the answer
	  
cout << "~" << "\n";
}
	  return 0;
}

// } Driver Code Ends