#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0; 

        for (int coin : coins) {
            for (int i = coin; i <= amount; i++) {
                if (dp[i - coin] != INT_MAX) {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }

        return (dp[amount] == INT_MAX) ? -1 : dp[amount];
    }
};

/*int Rec(vector<int>& coins, int amount)
    {
        // Base Case
        if(amount == 0)
            return 0;
        if(amount < 0)
            return INT_MAX;
        
        int mini = INT_MAX;
        for(int i = 0; i < coins.size(); i++)
        {
            int ans = Rec(coins,amount-coins[i]);
            if(ans != INT_MAX)
                mini = min(mini,1 + ans);
        }
        return mini;
    }*/


int main(){
    Solution s;
    vector<int> coins={1,2,5,10,50};
    int amount=109;
    int ans=s.coinChange(coins,amount);
    cout<<ans;
    return 0;
}
