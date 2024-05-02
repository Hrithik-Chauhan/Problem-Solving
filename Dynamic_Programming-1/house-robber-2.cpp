#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
     int solve(vector<int>& nums,int i,int l,vector<int>& cache){
        if(i>l)return 0;
        if(cache[i]!=-1){
            return cache[i];
        }
        cache[i]=max((nums[i]+solve(nums,i+2,l,cache)),solve(nums,i+1,l,cache));
        return cache[i];
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        vector<int> cache(nums.size()+1,-1);
        vector<int> cache1(nums.size()+1,-1);

       return max(solve(nums,1,nums.size()-1,cache),solve(nums,0,nums.size()-2,cache1));
    }
};
int main(){
    vector<int> nums={1,2,3,1};
    Solution s;
    int ans=s.rob(nums);
    cout<<ans;
    return 0;
}