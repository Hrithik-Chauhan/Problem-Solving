#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    int maxSum(int N, vector<vector<int>> mat)
    {
    int in = max(mat[0][0], mat[1][0]);
    int ex = 0, nex;

    for (int i = 1; i < N; i++) {
        nex = max(ex, in);
        in = ex + max(mat[0][i], mat[1][i]);
        ex = nex;
    }

    return max(ex, in);
    }
};
int main(){
    Solution sol;
    vector<vector<int>> s={{1, 4, 5}, 
       {2, 0, 0}};
    
    int numofdecoding=sol.maxSum(3,s);
    cout<<numofdecoding;
    return 0;

}