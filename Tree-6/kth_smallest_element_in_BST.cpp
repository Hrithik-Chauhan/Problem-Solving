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

void inorder(TreeNode* root,vector<int>& arr){
        if(root!=NULL){
            inorder(root->left,arr);
            arr.push_back(root->val);
            inorder(root->right,arr);
        }
        return;
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> arr;
        inorder(root,arr);
        return arr[k-1];
    }
     int main(){
         TreeNode* root=new TreeNode(8);
         root->left=new TreeNode(4);
         root->right=new TreeNode(11);
         root->left->left=new TreeNode(2);
         root->left->right=new TreeNode(6);
         root->right->left=new TreeNode(9);
         root->right->right=new TreeNode(16);
         int ans=kthSmallest(root,3);
        cout<<ans;
        return 0;
    }
