#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int solve(vector<int>& nums,int i,vector<int>& cache){
        if(i<0)return 0;
        if(cache[i]!=-1){
            return cache[i];
        }
        cache[i]=max((nums[i]+solve(nums,i-2,cache)),solve(nums,i-1,cache));
        return cache[i];
    }
    int rob(vector<int>& nums) {
        vector<int> cache(nums.size()+1,-1);
        return solve(nums,nums.size()-1,cache);
    }
};
int main(){
    Solution s;
    int n;
    cin>>n;
    vector<int> house(n);
    for(int i=0;i<n;i++){
        cin>>house[i];
    }
    int ans=s.rob(house);
    cout<<ans;
    return 0;
}