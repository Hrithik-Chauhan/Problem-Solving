#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int climbStairs(int n) {
        vector<int> p(n+1);
        p[0]=1;
        p[1]=1;
        for(int i=2;i<=n;++i){
            p[i]=p[i-1]+p[i-2];
           
        }
         return p[n];
    }
};
int main(){
    Solution s;
    int n;
    cin>>n;
    int ans=s.climbStairs(n);
    cout<<ans;
    return 0;
}
