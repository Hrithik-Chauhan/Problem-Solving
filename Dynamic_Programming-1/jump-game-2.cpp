#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;
        int cur = 0;
        int x = 0; 
        
        for (int i = 0; i < nums.size() - 1; i++) {
            x = max(x, i + nums[i]);
            if (i == cur) {
                jumps++;
                cur = x;
            }
        }
        
        return jumps;
    }
};
int main(){
    Solution s;
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int minsteps=s.jump(nums);
    cout<<minsteps;
    return 0;
}