
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& arr) {
         int mx=INT_MIN,csum=0;
    for(int i=0;i<arr.size();i++){
        csum+=arr[i];
        mx=max(mx,csum);
        if(csum<0)csum=0;
    }
    return mx;
    }
};

int main(){
    Solution s;
    vector<int> arr={1,2,5,10,50};
    int ans=s.maxSubArray(arr);
    cout<<ans;
    return 0;
}