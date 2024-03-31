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
void BST(TreeNode* r,int l,int h,int &s){
    if(r==NULL)return;
    if(r->val>=l && r->val<=h){
        s+=r->val;
    }
    if (l < r->val) {
            BST(r->left, l, h, s); 
    }
    if (h > r->val) {
            BST(r->right, l, h, s);
    }
}
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum=0;
        BST(root,low,high,sum);
        return sum;
    }
      int main(){
        TreeNode* root1=new TreeNode(7);
    root1->left=new TreeNode(5);
    root1->right=new TreeNode(10);
    root1->right->left=new TreeNode(9);
    root1->right->right=new TreeNode(11);

    int ans=rangeSumBST(root1,1,9);
    cout<<ans;
    return 0;
 }