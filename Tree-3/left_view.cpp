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

    void left(vector<int> &ans,TreeNode* root,int level){
    if(root==NULL)return;
    if(ans.size()<level)ans.push_back(root->val);
    left(ans,root->left,level+1);
    left(ans,root->right,level+1);
    }
    vector<int> leftSideView(TreeNode* root) {
        vector<int> ans;
        left(ans,root,1);
        return ans;
    }
    int main(){
    TreeNode* root=new TreeNode(3);
    root->left=new TreeNode(9);
    root->right=new TreeNode(20);
    root->right->left=new TreeNode(15);
    root->right->right=new TreeNode(7);
    
    vector<int> ans;
	ans=leftSideView(root);
	cout<<"[";
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<" ";
	}
	cout<<"]";
    return 0;
 }
