//Recursion + BFS
vector<vector<int> >zigzaglevelOrder(TreeNode *root)
{
	vector<vector<int> >res;
	zigzagTraverse(root, 1, res, true);
	return res;
}

void zigzaglevelOrder(Treenode *p, int level, vector<vector<int> > &res, bool left_to_right)
{
	if(!p) return ;
	
	//Create a vector array for each level
	if(level > res.size()) res.push_back();
	
	if(left_to_right) 
		res[level - 1].push_back(p->val);
	else 
		res[level - 1].insert(res[level - 1].begin(), p->val);
	zigzagTrverse(p->left, level + 1, res, !left_to_right);
	zigzagTrverse(p->right, level + 1, res, !left_to_right);
}

//********************************
//用队列进行层次遍历，当是奇数层的时候，对该层元素进行翻转
vector<vector<int> >zigzaglevelOrder_2(TreeNode *root)
{
	vector<vector<int> >array;
	if(!root) return array;
	queue<TreeNode *> que;
	que.push(root);
	while(!que.empty())
	{
		int size = que.size();
		vector<int> ans;
		while(size--)
		{
			TreeNode *curnode = que.front();
			ans.push_back(curnode->val);
			que.pop();
			if(curnode->left) que.push(curnode->left);
			if(curnode->right) que.push(curnode->right);
		}
		if(size % 2 != 0)
			reverse(ans.begin(), ans.end());
		array.push_back(ans);
	} 
	return array;
}

//***********************************
//用双队列 控制从头出列 入列 和从尾部出队入队 顺序 从而实现 不用翻转 而Z形遍历整棵树
vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > ans;
        if(root == NULL) return ans;
        deque<TreeNode*> dq; 
        dq.push_back(root);
        int zz = 0;
        while(dq.size())
        {
            vector<int> tmp;
            int h = dq.size();
            int l = 0;
            TreeNode *t;
            while(l < h)
            {
                if(zz % 2 == 0)
                {
                    t = dq.front();
                    dq.pop_front();
                    if(t->left)  dq.push_back(t->left);
                    if(t->right) dq.push_back(t->right);
                    tmp.push_back(t->val);
                    h--;
                }
                else
                {
                    t = dq.back();
                    dq.pop_back();
                    if(t->right) dq.push_front(t->right);
                    if(t->left) dq.push_front(t->left);
                    tmp.push_back(t->val);
                    h--;
                }
            }
            ans.push_back(tmp);
            zz ++;
        }
        return ans;
    }
