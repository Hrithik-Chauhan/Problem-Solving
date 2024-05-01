#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
int solve(vector<int>& dp,int n){
    if(n == 0){
        return 0;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    int ans=n;
    for(int i=1;i*i<=n;i++){
       ans=min(ans,1+solve(dp,n-(i*i)));
    }
    dp[n]=ans;
    return dp[n];
}
    int numSquares(int n) {
        vector<int> dp(n+1,-1);
        return solve(dp,n);
    }
};
int main(){
    Solution s;
    int n;
    cin>>n;
    int minsquares=s.numSquares(n);
    cout<<minsquares;
    return 0;
}