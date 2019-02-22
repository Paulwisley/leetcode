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

int maxPathSum(TreeNode *root){
    vector<int> nodes;
    if(!root) return -1;
    //traverse the bi tree, save the each node's val to vector
    traverseTree(root, nodes);
    for()
}

void traverseTree(TreeNode *root, vector<int> &nodes){
    //default the tree is not empty
    queue<TreeNode *>que;
    que.push(root);
    while (!que.empty()) {
        TreeNode *tmp = que.front();
        root.push_back(tmp->val);
        que.pop();
        if(tmp->left) que.push(tmp->left);
        if(tmp->right) que.push(tmp->right);
    }
}
