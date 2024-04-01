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
void Leaves(TreeNode* root,vector<int>& ans)
{
    if (root == NULL)
        return;
    Leaves(root->left,ans);
    if (!(root->left) && !(root->right))
        ans.push_back(root->val);
 
    Leaves(root->right,ans);
}
 
void BoundaryLeft(TreeNode* root,vector<int>& ans)
{
    if (root == NULL)
        return;
 
    if (root->left) {
        ans.push_back(root->val);
        BoundaryLeft(root->left,ans);
    }
    else if (root->right) {
        ans.push_back(root->val);
        BoundaryLeft(root->right,ans);
    }
}
void BoundaryRight(TreeNode* root,vector<int>& ans)
{
    if (root == NULL)
        return;
 
    if (root->right) {
        BoundaryRight(root->right,ans);
        ans.push_back(root->val);
    }
    else if (root->left) {
        BoundaryRight(root->left,ans);
         ans.push_back(root->val);
    }
}
 
vector<int> traverseBoundary(TreeNode *root)
{
	// Write your code here.
    vector<int> ans;
    if (root == NULL)
        return ans;
     ans.push_back(root->val);
    BoundaryLeft(root->left,ans);
    Leaves(root->left,ans);
    Leaves(root->right,ans);
    BoundaryRight(root->right,ans);
    return ans;
}
 int main(){
    TreeNode* root=new TreeNode(7);
    root->left=new TreeNode(5);
    root->right=new TreeNode(10);
    root->right->left=new TreeNode(9);
    root->right->right=new TreeNode(11);
   vector<int> ans=traverseBoundary(root);
   for(auto i:ans){
    cout<<i<<" ";
   }
    return 0;
 }
