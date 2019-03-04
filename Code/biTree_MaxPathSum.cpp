#include <iostream>
#include <vector>
#include <queue>
using namespce std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x),left(NULL), right(NULL){}
};

int MAX = INT_MIN;

int maxPathSum(TreeNode *root){
    if(root == NULL)
        return 0;
    helper(root);
    return MAX;
}

int helper(TreeNode *root){
    if(!root){
       return 0;
    }
    int lnode = max(0, helper(root->left));
    int rnode = max(0, helper(root->right));
    MAX = max(root->val + lnode + rnode, MAX);
    return max(0,max(lnode, rnode) + root->val);
}

