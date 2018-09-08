int MaxDepth(TreeNode *root)
{
	if(!root) return 0;
	int left = MaxDepth(root->left); //依次递归左右子树
	int right = MaxDepth(root->right);
	return max(left, right) + 1; 
}

int MaxDepth(TreeNode *root)
{
	//非递归 采用层次遍历 借助队列
	queue<TreeNode*> que;
	int depth = 0;
	//the first step , seperate the null-pointer staus
	if(!root)  return 0;
	que.push(root);
	while(!que.empty())
	{
		depth++;
		int cursize = que.size();
		while(cursize--)// travelsal each floor
		{
			TreeNode *tmp = que.front();
			que.pop();
			if(tmp->left)  que.push(tmp->left);
			if(tmp->right) que.push(tmp->right);
 		} 
	}
	return depth;
}

