#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 TreeNode* Solve(TreeNode* r,int v){
          if(r==NULL){
            return new TreeNode(v);
          }
          if(v<r->val){
             r->left=Solve(r->left,v);
          }
          else{
            r->right=Solve(r->right,v);
          }
          return r;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
       TreeNode* r=NULL;
       for(int i=0;i<preorder.size();i++){
           r=Solve(r,preorder[i]);
       }
       return r;
        
    }
    void print(TreeNode* r){
        if(r==NULL)
        {
            return;
        }
        print(r->left);
        cout<<r->val<<" ";
        print(r->right);

    }
int main(){
     vector<int> vec={8,5,1,7,10,12};
     TreeNode* r=bstFromPreorder(vec);
     print(r);
     return 0;
}