#include<bits/stdc++.h>
using namespace std;
vector<int> dp(101,-1);
class Solution {
public:
int n=0;
    int solve(string s,int pos){
        
        if(pos==n) return 1;
        if(s[pos]=='0') return 0;
        if(dp[pos]!=-1) return dp[pos];
        int count=solve(s,pos+1);
        if(pos<n-1 && s.substr(pos,2)<"27"){
            count+=solve(s,pos+2);
        }
        return dp[pos]=count;
    }
    int numDecodings(string s) {
        n=s.size();
        fill(dp.begin(),dp.end(),-1);
        return solve(s,0);
    }
};
int main(){
    Solution sol;
    string s;
    cin>>s;
    int numofdecoding=sol.numDecodings(s);
    cout<<numofdecoding;
    return 0;

}