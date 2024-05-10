#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:

    // Recursion
    /*
    int solveRec(int n) 
    { 
        if(n<=2) return n;
        return solveRec(n-1)+ (n-1)*solveRec(n-2);
    }


    //  Memoisation
    int solveMemo(int n, vector < int > & dp) {
        if (n <= 2) return n;
        if (dp[n] != -1) return dp[n];
        return dp[n] = solveMemo(n - 1, dp) + (n - 1) * solveMemo(n - 2, dp);
    }
    */

    // DP
    int solveDP(int n) 
    { 
        vector<int> dp(n+1,0);
        dp[0]=1;  
        dp[1]=1;  
        
        for(int i=2;i<=n;i++)
        {
            dp[i]=1*dp[i-1] + (i-1)*dp[i-2];
        }
        return dp[n];
    }

    
    int countFriendsPairings(int n){
        return solveDP(n);
    }
}; 
int main(){
    int n;
    cin>>n;
    Solution s;
    int ans=s.countFriendsPairings(n);
    cout<<ans;
    return 0;
}