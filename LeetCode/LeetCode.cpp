// OJ-LeetCode-test.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

vector<int> plusOne(vector<int>& digits) {
	int curindex = digits.size() - 1;
	while (curindex >= 0 && digits[curindex] == 9) {
		digits[curindex] = 0;
		curindex--;
	}
	if (curindex < 0) digits.insert(digits.begin(), 1);
	else ++digits[curindex];
	return digits;
}

int search(vector<int>& nums, int target) {
	int length = nums.size();
	int i = 0;
	int j = length - 1;
	while (i < j)
	{
		if (target == nums[i])
			return i;
		if (target == nums[j])
			return j;
		if (target < nums[i])
			i++;
		if (target < nums[j])
			j--;
	}
	return -1;
}

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
	if (!n) return;
	int i = 0;
	int j = 0;
	while (i<m)
	{
		if (nums1[i] < nums2[j])
		{
			i++;
		}
		else
		{
			for (int k = m - 1; k>i; k--)
				nums1[k + 1] = nums1[k];
			nums1[i + 1] = nums2[j];
			m++;
			j++;
		}
	}
	while (j<n)
	{
		nums1[m] = nums2[j];
		j++;
		m++;
	}
}

int jump(int A[], int n) {
	int step = 1;
	int i;
	int curend = 0;
	int newend = 0;
	if (n <= 1) return 0;
	for (i = 0; i <= curend; i++)
	{
		newend = max(newend, i + A[i]);
		cout << curend << endl;
		if (newend >= (n - 1))
			return step;
		if (i == curend)
		{
			curend = newend;
			step++;
		}

	}
	return INT_MAX;
}
int removeDuplicates(int A[], int n) {
	int dif = 1;
	int same = 0;
	if (!n) return 0;
	vector<int> tmp;
	for (int i = 0; i < n - 1; i++)
	{
		if (A[i] == A[i + 1])
		{
			tmp.push_back(A[i]);
		}
		else
		{
			dif++;
			tmp.push_back(A[i + 1]);
		}
	}
	int m = tmp.size();
	cout << m << endl;
	for (int i = 0; i < m; i++)
	{
		A[i] = tmp[i];
	}
	A[m + 1] = '\0';

	return dif;
}
string longestCommonPrefix(vector<string>& strs) {
	string ans = "";
	if (strs.empty()) return ans;
	int len = strs.size();
	int i = 0;
	int lmin = 9999;
	while (len--)
	{
		if (strs[i].size() < lmin)
			lmin = strs[i].size();
		i++;
	}
	i = 0;
	int j = 0;
	len = strs.size();
	while (i < lmin)
	{
		int tag = 0;
		for (j = 0; j < len - 1; j++)
		{
			if (strs[j][i] == strs[j + 1][i])
				tag++;
			else
			{
				tag = 0;
			}
		}
		if (tag == len - 1)
			ans += strs[j][i];
		else
			ans += "";
		i++;
	}

	return ans;
}

struct UndirectedGraphNode
{
	int label;
	vector<UndirectedGraphNode*> neighbors;
	UndirectedGraphNode(int x) : label(x) {};
};


//UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
//	if (!node) return nullptr;
//	UndirectedGraphNode *origin = node;
//	UndirectedGraphNode *clone = new UndirectedGraphNode(node->label);
//	unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> map;
//	queue<UndirectedGraphNode*> que;
//	que.push(node);
//	map[node] = clone;
//	while (!que.empty())
//	{
//		UndirectedGraphNode *tmp = que.front();
//		que.pop();
//		for (auto val : tmp->neighbors)
//		{
//			if (map.find(val) == map.end())
//			{
//				map[val] = new UndirectedGraphNode(val->label);
//				que.push(val);
//			}
//			map[tmp]->neighbors.push_back(map[val]);
//		}
//	}
//	return map[node];
//}

void nextPermutation(vector<int>& nums) {
	//sort(nums.begin(), nums.end());
	if (nums.empty()) return;
	int len = nums.size();
	//sort(nums.begin() + 1, nums.end());
	//int changed = 1;//change标签，记录数组是否有改动，没有改动则从小到大排列数组
	for (int i = len - 1; i > 0; i--) //从后往前遍历，遇到逆序则停止，在遍历过的数中找第一个大于当前数的值 交换
	{
		if(nums[i] > nums[i-1])
		{
			sort(nums.begin()+i, nums.end());
			//cout << "当前数为：" << i << endl;
			for (int j = i; j < len ; j++)
			{
				if (nums[j] > nums[i - 1])
				{
					nums[j] = nums[j] ^ nums[i - 1];
					nums[i-1] = nums[j] ^ nums[i - 1];
					nums[j] = nums[j] ^ nums[i - 1];
					//可以直接用swap
					//changed = 0;
					break;
				}
			}
			return;
		}

	}
sort(nums.begin() , nums.end());
//auto smallest1 = std::min_element(std::begin(nums) + 1, std::end(nums));
//int tmp1;
//tmp1 = nums[0];
//nums[0] = *smallest1;
//*smallest1 = tmp1;
//auto smallest2 = std::min_element(std::begin(nums) + 1, std::end(nums));
//int tmp2;
//tmp2 = nums[1];
//nums[1] = *smallest2;
//*smallest2 = tmp2;

}

//判断括号匹配是否有效
bool isValid(string s) {
	stack<char> pair;
	if (s.empty()) return false;
	int len = s.size();
	map<char, int> pairmap;
	pairmap['('] = 1;
	pairmap[')'] = -1;
	pairmap['{'] = 2;
	pairmap['}'] = -2;
	pairmap['['] = 3;
	pairmap[']'] = -3;
	pair.push(s[0]);
	for (int i = 1; i < len; i++)
	{
		cout << pair.top() << endl;
		if (pairmap[s[i]] + pairmap[pair.top()] == 0)
		{			
			pair.pop();
		}
		else
			pair.push(s[i]);
		if (pair.empty() && i < len-1)
		{
			pair.push(s[++i]);
			cout << "cur = "<<pair.top() << endl;
		}
	}
	if (pair.empty())
		return true;
	else
		return false;
}



//binary search tree
//vector<TreeNode *> generateTrees(int n) {
//	vector<TreeNode*> Trees;
//	if (!n) return Trees;
//
//}
//vector<TreeNode*> helper(int x,int n)
//{
//
//}

struct ListNode
{
	int val;
	ListNode *next;
	ListNode (int x) : val(x), next(NULL) {}
};

ListNode *detectCycle(ListNode *head) {
	vector<ListNode*> tmp;
	ListNode *p = head;
	while (p)
	{
		vector<ListNode*>::iterator result = find(tmp.begin(), tmp.end(), p);
		if (result == tmp.end())
		{
			tmp.push_back(p);
			p = p->next;
		}
		else
			return p;
	}
	return nullptr;

}

//int minimumTotal(vector<vector<int>>& triangle) {
//	//int min;
//	if (triangle.empty())
//		return 0;
//	vector<int> ans;
//	//ans.push_back(triangle[0][0]);
//	for (int i = 0; i < triangle.size() - 1; i++)
//	{
//		int len = triangle[i].size();
//		vector<int> tmp(ans.begin(),ans.end());
//		for (int j = 1; j < len - 1; j++)
//		{
//			int x1 = tmp[j-1] + triangle[i][j];
//			int x2 = tmp[j] + triangle[i][j];
//			ans[j] = min(x1, x2);
//		}
//		ans[0] += triangle[i][0];
//		ans[len - 1] += triangle[i][len - 1];
//	}
//	vector<int>::iterator smallest = std::min_element(ans.begin(), ans.end());
//	//cout << *smallest << endl;
//	return 0;
//}

int minimumTotal(vector<vector<int> > &triangle) {
	vector<int> res(triangle.back());
	for (int i = triangle.size() - 2; i >= 0; --i)
	{
		for (int j = 0; j < triangle[i].size(); ++j)
		{
			res[j] = triangle[i][j] + min(res[j],res[j+1]);
		} 
	}
	return res[0];
}

int minDistance(string word1, string word2) {
	int len1 = word1.length();
	int len2 = word2.length();
	vector<vector<char> > common(len1+1, vector<char>(len2+1));
	if (word1.empty()) return len2;
	if (word2.empty()) return len1;
	for (int i = 0; i <= len1; i++)
		common[i][0] = i;
	for (int j = 0; j <= len2; j++)
		common[0][j] = j;
	for (int i = 1; i <= len1; i++)
	{
		for (int j = 1; j <= len2; j++)
		{
			if (word1[i-1] == word2[j-1])
				common[i][j] = common[i - 1][j - 1];
			else
				common[i][j] = min(common[i-1][j] + 1, min(common[i][j-1] + 1,common[i-1][j-1]+1));
		}
	} 
	return common[len1][len2];
}

string mp[12] = { "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
vector<string> letterCombinations(string digits) {
	vector<string> ans(1, "");
	for (int i = 0; i<digits.size(); i++) {
		vector<string> tmp;
		for (int j = 0; j<ans.size(); j++)
			for (int k = 0; k<mp[digits[i] - '0'].size(); k++)
				tmp.push_back(ans[j] + mp[digits[i] - '0'][k]);
		ans = tmp;
	}
	return ans;
}

struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

RandomListNode *copyRandomList(RandomListNode *head)
{
	if (!head) return NULL;
	RandomListNode *p, *copy;// p : active pointer, copy : save the dummy node
	//step 1 copy the origin next node
	for (p = head; p; p = p->next) {
		copy = new RandomListNode(p->label);
		copy->next = p->next; // insert new at old next
		p = p->next = copy;
	}
	//step 2 copy the random node 
	for (p = head; p; p = copy->next) {
		copy = p->next;          // copy random point
		copy->random = (p->random ? p->random->next : NULL);
	}
	//step 3 split node
	for (p = head, head = copy = p->next; p;) {
		p = p->next = copy->next; // split list
		copy = copy->next = (p ? p->next : NULL);
	}
	return head;
}
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};

class PathSum{
private:
	vector<vector<int> >ans;
public:
	vector<vector<int> > pathSum(TreeNode *root, int sum) {
		vector<vector<int> >ans;
		vector<int> node;
		helper(root, sum, node, ans);
		return ans;
	}
	void helper(TreeNode *root, int res, vector<int>curnode, vector<vector<int> >&nodes) {
		if (!root) return;
		curnode.push_back(root->val);
		if (!root->left && !root->right && res == 0)
			nodes.push_back(curnode);
		helper(root->left,res-root->val,curnode,nodes);
		helper(root->right,res-root->val,curnode,nodes);
	}

};

class MidSearch
{
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		if (nums.empty()) return {};
		int len = nums.size();
		int start = helpsearch(nums,target);
		int end = helpsearch(nums, target + 1) - 1;
		if (nums[start] == target && start < len)
			return { start , end };
		else
			return {-1, -1};

	}
	int  helpsearch(vector<int>nums, int target)
	{
		int left = 0;
		int right = nums.size() - 1;
		while (left <= right)
		{
			int mid = (right - left) / 2 + left;
			if (nums[mid] < target)
				left = mid + 1;
			else
				right = mid - 1;
		}
		return left;
	}
};

int longestConsecutive(vector<int> &num) {
	if (num.empty()) return 0;
	sort(num.begin(), num.end());
	int max = 1;
	int cur = 1;
	for (int i = 0; i < num.size() - 1; i++)
	{
		if (num[i + 1] - num[i] == 1)
			cur++;
		else if (num[i] == num[i + 1])
			continue;
		else
			cur = 1;
		max = max > cur ? max : cur;
	}
	return max;
}

TreeNode *helper(vector<int> &nums, int left, int right)
{
	if (left > right)
		return NULL;
	else
	{
		int mid = (right - left) / 2 + left;
		TreeNode *newnode = new TreeNode(nums[mid]);
		newnode->left = helper(nums, left, mid-1);
		newnode->right = helper(nums, mid+1, right);
		return newnode;
	}
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
	int len = nums.size();
	sort(nums.begin(), nums.end());
	TreeNode *root = helper(nums, 0, len - 1);
	return root;
}


int maxProfit(vector<int>& prices) {
	int len = prices.size();
	vector<vector<int> >res(len, vector<int>(len, 0));
	for (int i = 0; i < len; i++)
	{
		for (int j = i; j < len; j++)
		{
			res[i][j] = prices[j] - prices[i];
		}
	}

	return 0;

}

TreeNode *helper(vector<int>&inorder,int instart,int inend,vector<int>&postorder,int pstart,int pend)
{
	if (instart >= inend || pstart >= pend)
		if (instart > inend || pstart > pend)
			return NULL;
	int mid = postorder[pend];
	TreeNode *root = new TreeNode(mid);
	auto f = find(inorder.begin() + instart, inorder.begin() + inend, mid);
	int index = f - inorder.begin();//attain the index of the each root
	//cout << index << endl;
	root->left = helper(inorder, instart, index - 1, postorder, pstart, pstart + index - instart - 1); //index - instart = diff
	root->right = helper(inorder, index + 1, inend, postorder, pstart + index - instart, pend - 1);
	return root;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
	return  helper(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1);
}

string addBinary(string a, string b) {
	int alen = a.size()-1;
	int blen = b.size()-1;
	string sum = "";
	int c = 0, s = 0;
	while (alen|| blen||c>0)
	{
		int num1 = alen >= 0 ? a[alen--] - '0' : 0;
		int num2 = blen >= 0 ? b[blen--] - '0' : 0;
		s = num1 + num2 + c;
		c = s >> 1;
		sum = char(s%2 + '0') + sum;
	}
	return sum;
}

double myPow(double x, int n) {
	int c = n > 0 ? 1 : 0;
	n = abs(n);
	while (n--)
	{
		x *= x;
	}
	return 0.0;
}

class  Combination {
public:
	void chelper(vector<int> candidates, int target, vector<int> curr, vector<vector<int> > &result, int index)
	{
		if (target == 0)
		{
			result.push_back(curr);
			//cout << curr.size();
			return;
		}
		else
		{
			for (int i = index; i < candidates.size(); i++)
			{
				if (candidates[i] > target) break;
				curr.push_back(candidates[i]);
				chelper(candidates, target - candidates[i], curr, result, i);
				curr.pop_back();
			}
		}
	}
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<vector<int> > result;
		vector<int> curr;
		sort(candidates.begin(), candidates.end());
		if (candidates.empty())
			return result;
		chelper(candidates, target, curr, result, 0);
		return result;
	}

	void chelper2(vector<int>candidates, vector<vector<int> >&ans, vector<int>curr,vector<int>&used, int target, int index){
		if (target == 0)
		{
			ans.push_back(curr);
			return;
		}
		else
		{
			for (int i = index; i < candidates.size()&& candidates[i] <= target; i++){
				if(used[i]||i>0&&candidates[i] == candidates[i-1] && !used[i-1]) continue;
				curr.push_back(candidates[i]);
				used[i] = 1;
				chelper2(candidates, ans, curr, used, target - candidates[i], i+1);
				curr.pop_back();
				used[i] = 0;
			}
		}
	}
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		if (candidates.empty()) return {};
		vector<vector<int> > ans;
		vector<int> curr;
		vector<int> used(candidates.size(), 0);
		sort(candidates.begin(), candidates.end());
		chelper2(candidates, ans, curr,used, target, 0);
		return ans;
	}
};

class Permute {
public:
	vector<vector<int> >permuteUnique(vector<int>&nums)
	{
		if (nums.empty()) return {};
		vector<vector<int> > result;
		vector<int> curr;
		vector<int> used(nums.size(), 0);
		sort(nums.begin(),nums.end());
		help(result, nums, curr, used);
		return result;
	}

	void help(vector<vector<int> >&result, vector<int>&nums, vector<int> &curr, vector<int> &used)
	{
		if (curr.size() == nums.size())
		{
			result.push_back(curr);
			return;
		}
		for (int i = 0; i < nums.size() ; i++)
			{
				if (used[i]||(i>0 && nums[i] == nums[i-1] && !used[i-1]))  continue;
				used[i] = 1;
				curr.push_back(nums[i]);
				help(result, nums, curr, used);
				used[i] = 0;
				curr.pop_back();
			}
	}

	vector<vector<int>> combine(int n, int k) {
		if (n < k) return {};
		vector<vector<int> > ans;
		vector<int> curr;
		//vector<int> used(n, 0);
		combinehelp(ans, curr, n, k, 1);
		return ans;
	}
	void combinehelp(vector<vector<int> > &ans, vector<int> curr, int n, int k, int index)
	{
		int size = curr.size();
		if (curr.size() == k)
		{
			ans.push_back(curr);
			return;
		}
		for (int i = index; i <= n - (k - size - 1); i++)
		{
			curr.push_back(i);
			combinehelp(ans, curr, n, k, i + 1);
			curr.pop_back();
		}
	}

	/*
	Given a string s, partition s such that every substring of the partition is a palindrome.
	Return all possible palindrome partitioning of s.
	@131 Medium
	*/
	vector<vector<string>> partition(string s) {
		vector<vector<string>>ans;
		vector<string> cur;
		if (s.empty()) return ans;
		helper_partion(s, cur, ans);
		return ans;
	}

	void helper_partion(string s, vector<string>&cur,vector<vector<string> >&ans) {
		if (s.empty()) {
			ans.push_back(cur);
			return;
		}
		for (int i = 1; i <= s.size(); i++) {
			if (isPalindrome(s.substr(0, i)))
			{
				cur.push_back(s.substr(0, i));
				helper_partion(s.substr(i),cur,ans);
				cur.pop_back();
			}
		}
	}

	bool isPalindrome(string s) {
		int len = s.size();
		for (int i = 0; i < len / 2; i++) {
			if (s[i] != s[len - i - 1])
				return false;
		}
		return true;
	}

};

class GroupAnagrams {
public:
	vector<vector<string> > groupAnagrams(vector<string>& strs) {
		vector<vector<string> > result;
		if (strs.empty()) return result;
		map<string, vector<string>> mp;
		for (int i = 0; i < strs.size(); i++)
		{
			transform(strs[i].begin(), strs[i].end(), strs[i].begin(), ::tolower);
			string tmp = strs[i];
			sort(tmp.begin(), tmp.end());
			mp[tmp].push_back(strs[i]);

		}
		map<string, vector<string> >::iterator it;
		it = mp.begin();
		while (it != mp.end())
		{
			result.push_back(it->second);
			it++;
		}
		return result;
	}

	vector<string> anagrams(vector<string> &strs) {
		vector<string> result;
		if (strs.empty()) return result;
		map<string, vector<string> > mp;
		for (int i = 0; i < strs.size(); i++)
		{
			string tmp = strs[i];
			sort(tmp.begin(), tmp.end());
			mp[tmp].push_back(strs[i]);
		}
		map<string, vector<string>>::iterator it;
		it = mp.begin();
		while (it != mp.end())
		{
			if (it->second.size()>1)
			{
				result.insert(result.end(),it->second.begin(),it->second.end());
			}
			it++;
		}
		return result;
	}
};

class BST {
public:
	void recoverTree(TreeNode *root)
	{
		if (!root) return;
		TreeNode *cur = root;
	}

	bool isValidBST(TreeNode* root) {
		stack<TreeNode*> s;
		vector<int> nodes;
		TreeNode *pnode = root;
		while (!s.empty()|| !pnode)
		{
			if (!pnode)
			{
				s.push(pnode);
				pnode = pnode->left;
			}
			else
			{
				TreeNode *tmp = s.top();
				s.pop();
				nodes.push_back(tmp->val);
				pnode = tmp->right;
			}
		}
		int tmp = nodes[0];
		for (int i = 1; i < nodes.size(); i++)
		{
			if (tmp >= nodes[i]) return false;
			tmp = nodes[i];
		} 
		return  true;
	}

	//递归版
	//bool isValidBST(TreeNode* root) {
	//	return isValidBST(root, LONG_MIN, LONG_MAX);
	//}

	//bool isValidBST(TreeNode* root, long min, long max) {
	//	if (root == NULL) return true;
	//	if (root->val <= min || root->val >= max) return false;
	//	return isValidBST(root->left, min, root->val) && isValidBST(root->right, root->val, max);
	//}

};

class LinkListSolve {
public:
	ListNode *deleteDuplicates(ListNode *head) {
		if (!head) return nullptr;
		ListNode *p = head;
		ListNode * newhead = (ListNode*)malloc(sizeof(ListNode));
		ListNode *m = newhead;
		vector<int> nodes;
		while (p->next != nullptr)
		{
			if (p->val == p->next->val)
			{
				nodes.push_back(p->val);
				p = p->next;
			}
			else
			{
				vector<int> ::iterator it = find(nodes.begin(), nodes.end(), p->val);
				if (it == nodes.end())
				{
					ListNode *n = new ListNode(p->val);
					m->next = n;
					m = n;
				}
				p = p->next;
			}
		}
		vector<int> ::iterator it = find(nodes.begin(), nodes.end(), p->val);
		if (it == nodes.end())
		{
			ListNode *n = new ListNode(p->val);
			m->next = n;
			m = n;
		}
		m->next = NULL;
		return newhead->next;
	}

	ListNode* reverseKGroup(ListNode* head, int k) {
		if (!head||k==1) return nullptr;
		int num = 0;
		ListNode *prehead = new ListNode(-1);
		prehead->next = head;
		ListNode *pre = prehead;
		ListNode *cur = prehead;
		ListNode *nex;
		while (cur = cur->next)
			num++;
		while (num>=k)
		{
			cur = pre->next;
			nex = cur->next;
			for (int i = 1; i < k; i++)
			{
				cur->next = nex->next;
				nex->next = pre->next;
				pre->next = nex;
				nex = cur->next;
			}
			pre = cur;
			num -= k;
		}
		return prehead->next;
	}

	/*
	sort listnode with insert-sort
	@Medium
	*/
	ListNode* insertionSortList(ListNode* head) {
		if (head == nullptr) {
			return head;
		}
		ListNode *prehead = new ListNode(0); //temporary pointer as the stand guard
		prehead->next = head;
		ListNode *pre = head;//first active pointer
		ListNode *p = pre->next;//second active poniter
		prehead->val = pre->val;
		while (p)
		{
			if (pre->val > p->val) 
			{
				if(p->val < prehead->val)
					prehead->val = p->val;
				ListNode *cur = prehead;
				while (p->val > cur->val && p->val > cur->next->val)
				{
					cur =  cur->next;
				}
				pre->next = p->next;
				p->next = cur->next;
				cur->next = p;
				p = pre->next;
			}
			else
			{
				pre = pre->next;
				p = pre->next;
				//prehead->val = p->val;
			}
		}
		return prehead->next;
	}

	/*
	Merge k sorted linked lists and return it as one sorted list.
	@Hard
	*/

	//stupid solution merge all these lists then sort
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		int k = lists.size();
		ListNode *head = new ListNode(0);
		ListNode *p = head;
		//merge all the nodes as one list
		while (k--)
		{
			p->next = lists[k];
			while (p->next)
			{
				p = p->next;
			}
		}
		//sort
		quicksortList(head->next, NULL);
		return head->next;
	}
	void quicksortList(ListNode *head, ListNode *tail)
	{
		//the list's range: [low, high)
		if (head != tail && head->next != tail)
		{
			ListNode* mid = partionlist(head, tail);
			quicksortList(head, mid);
			quicksortList(mid->next, tail);
		}
	}
	ListNode *partionlist(ListNode *low, ListNode *high)
	{
		//the list's range: [low, high)
		int key = low->val;
		ListNode* loc = low;
		for (ListNode*i = low->next; i != high; i = i->next)
			if (i->val < key)
			{
				loc = loc->next;
				swap(i->val, loc->val);
			}
		swap(loc->val, low->val);
		return loc;
	}


	/*
	Sort a linked list in O(n log n) time using constant space complexity.
	@148 Medium
	*/
	ListNode* sortList(ListNode* head) {
		if (!head) return head;
		head = mergesort(head);
		return head;
	}
	ListNode* mergesort(ListNode* head)
	{
		if (head == NULL || head->next == NULL)
			return head;
		ListNode* fast = head->next;
		ListNode* slow = head;
		while (fast!=NULL && fast->next!=NULL)
		{
			fast = fast->next->next;
			slow = slow->next;
		}
		ListNode* mid = slow->next;
		slow->next = NULL;
		ListNode* left = mergesort(head);
		ListNode* right = mergesort(mid);
		return merge(left, right);
	}
	ListNode* merge(ListNode* left, ListNode* right)
	{
		if (left == NULL)
			return right;
		if (right == NULL)
			return left;
		ListNode* newhead = new ListNode(0);
		ListNode*p = newhead;
		while(left && right)
		{
			if (left->val < right->val)
			{
				p->next = left;
				left = left->next;
			}
			else
			{
				p->next = right;
				right = right->next;
			}
			p = p->next;
		}
		ListNode* res = (left) ? left : right;
		p->next = res;
		return newhead->next;
	}

	/*
	Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
	@109 Medium
	*/
	TreeNode* sortedListToBST(ListNode* head) {
		if (head == NULL)    return NULL;
		if (head->next == NULL) return new TreeNode(head->val);
		ListNode* slow = head, *fast = head, *pre = slow;
		while (fast && fast->next) {
			fast = fast->next->next;
			pre = slow;
			slow = slow->next;
		}
		fast = slow->next;
		pre->next = NULL;
		TreeNode* root = new TreeNode(slow->val);
		if (head != slow)
			root->left = sortedListToBST(head);
		root->right = sortedListToBST(fast);
		return root;
	}


	/*
	@92. Reverse Linked List II  
	Medium
	Reverse a linked list from position m to n. Do it in one-pass.
	Note: 1 ≤ m ≤ n ≤ length of list.
	*/
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		if (!head || m >= n) return head;
		/*
		def:
		p pointer as the active one
		pre pointer the previous one
		*/
		ListNode *pre = new ListNode(0);
		ListNode *newhead = pre;
		pre->next = head;
		ListNode *p = head;
		int count = 1;
		while (count < m && p){
			p = p->next;
			pre = pre->next;
			count++;
		}
		//pre save the n-1 pointer
		stack<ListNode*> tmp;
		while (count <= n && p){
			tmp.push(p);
			p = p->next;
			count++;
		}
		while (!tmp.empty()){
			pre->next = tmp.top();
			pre = pre->next;
			tmp.pop();
		}
		pre->next = p;
		return newhead->next;
	}
};

class TreeSpecial {
public:
	int sumNumbers(TreeNode* root) {
		if (!root) return 0;
		vector<vector<int>> ans;
		vector<int> curr;
		TravereTree(root, curr, ans);
		int sum = 0;
		for (int i = 0; i < ans.size(); i++)
		{
			int tmp = ans[i][0];
			for (int j = 1; j < ans[i].size(); j++)
			{
				tmp = tmp * 10 + ans[i][j];
			}
			sum += tmp;
		}
		return sum;
	}
	void TravereTree(TreeNode *root, vector<int>res,vector<vector<int>>&ans )
	{
		if (root->left == NULL && root->right == NULL)
		{
			res.push_back(root->val);
			ans.push_back(res);
			return;
		}
		else
		{
			res.push_back(root->val);
			if (root->left)
				TravereTree(root->left, res, ans);
			if (root->right)
				TravereTree(root->right, res, ans);
		}
	}
};

class StringQuestions
{
public:
	bool isScramble(string s1, string s2) 
{
	if (s1 == s2)
		return true;

	int len = s1.length();
	int count[26] = { 0 };
	//确保S1中含有的元素在S2中都有 否则，直接return false
	for (int i = 0; i<len; i++)
	{
		count[s1[i] - 'a']++;
		count[s2[i] - 'a']--;
	}

	for (int i = 0; i<26; i++)
	{
		if (count[i] != 0)
			return false;
	}

	for (int i = 1; i <= len - 1; i++)
	{
		if (isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i)))
			return true;
		if (isScramble(s1.substr(0, i), s2.substr(len - i)) && isScramble(s1.substr(i), s2.substr(0, len - i)))
			return true;
	}
	return false;
}

	/*
	Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*'.
	@Hard
	*/
	bool isMatch(string s, string p) {
		if (p.empty()) return s.empty();
		if (p[1] == '*')
		{
			return(isMatch(s, p.substr(2)) || !s.empty() && (s[0] == p[0] || '.' == p[0]) && isMatch(s.substr(1), p));
		}
		else
		{ 
			return!s.empty() && (s[0] == p[0] || '.' == p[0]) && isMatch(s.substr(1), p.substr(1));
		}
	}

	/*
	Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.
	If the last word does not exist, return 0.
	@easy
	*/
	int lengthOfLastWord(const char *s) {
	int len = 0, tail = strlen(s) - 1;
	while (tail >= 0 && s[tail] == ' ') tail--;
	while (tail >= 0 && s[tail] != ' ') {
		len++;
		tail--;
	}
	return len;
}

	/*
	Given a 2D board and a word, find if the word exists in the grid.
	The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are 
	those horizontally or vertically neighboring. The same letter cell may not be used more than once.
	@79  Medium
	*/
	bool exist(vector<vector<char>>& board, string word) {
		vector<vector<int> >visited(board.size(), vector<int>(board[0].size(), 0));
		for (int i = 0; i < board.size(); i++) {
			int count = 0;
			auto start = find(board[i].begin(),board[i].end(),word[count]);
			if (start == board[i].end())
				continue;
			else
			{
				int index = start - board[i].begin();
				visited[i][index] = 1;
				for (int j = index; j < board[i].size(); j++) {
					
				}
			}
		}
	}

	/*
	Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).
	@76  Hard
	*/
	string minWindow(string S, string T) {
		if (S.size() == 0 || T.size() == 0) return "";
		vector<int> remaining(128, 0);
		int required = T.size();
		for (int i = 0; i < required; i++) remaining[T[i]]++;
		// left is the start index of the min-length substring ever found
		int min = INT_MAX, start = 0, left = 0, i = 0;
		while (i <= S.size() && start < S.size()) {
			if (required) {
				if (i == S.size()) break;
				remaining[S[i]]--;
				if (remaining[S[i]] >= 0) required--;//若在第二次查询过程中 再次找到 则-1
				i++;
			}
			else {
				if (i - start < min) {
					min = i - start;
					left = start;
				}
				remaining[S[start]]++;
				if (remaining[S[start]] > 0) required++;//找到 required+1 
				start++;//找到第一个包含T元素的位置
			}
		}
		return min == INT_MAX ? "" : S.substr(left, min);
	}

	/*
	Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.
	*/
	string multiply(string num1, string num2) {

	}

};

class NumProblems {
public:
	/*
	Given two integers dividend and divisor, divide two integers without using multiplication, division and mod operator.
	@29 Medium
	*/
	int divide(int dividend, int divisor) {
		if (!divisor || (dividend == INT_MIN && divisor == -1))
			return INT_MAX;
		int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1; //利用异或获取结果的最终符号
		long long dvd = labs(dividend);
		long long dvs = labs(divisor);
		int res = 0;
		while (dvd >= dvs) {
			long long temp = dvs, multiple = 1;
			//利用位运算加快计算
			while (dvd >= (temp << 1)) {
				temp <<= 1;
				multiple <<= 1;
			}
			dvd -= temp;
			res += multiple;
		}
		return sign == 1 ? res : -res;
	}

	/*
	Given an unsorted integer array, find the smallest missing positive integer.
	@41 Hard
	*/
	int firstMissingPositive(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		//check where is the first num locates
		auto index = find(nums.begin(),nums.end(),1);
		int start = 2;
		if (index == nums.end())
			return 1;
		else
		{
			for (int i = index-nums.begin()+1; i < nums.size(); i++) {
				if (nums[i] == start)
					++start;
				else
					return start;
			}
		}
	}

	/*
	Given an array of integers, return indices of the two numbers such that they add up to a specific target.
	@ 01 Easy
	*/
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> ans(2,0);
		unordered_map<int, int>mp;
		for (int i = 0; i < nums.size(); i++) {
			if (mp.find(nums[i]) != mp.end()) {
				ans[0] = mp[nums[i]];
				ans[1] = i;
			}
			else {
				mp[target - nums[i]] = i;
			}
		}
		return ans;
	}
};

class DivideNConquer {
public:
	/*
	93. Restore IP Addresses
	@Medium
	Given a string containing only digits, restore it by returning all possible valid IP address combinations.
	*/
	vector<string> restoreIpAddresses(string s) {
		vector<string>res;
		if (s.size() < 4 || s.size() > 12)
			return res;
		helper(s,"",0 ,res);
		return res;
	}
	void helper(string s, string out, int part,vector<string>&res) {
		if (part == 4) {
			if (s.empty()) res.push_back(out);
		}
		else
		{
			for (int i = 1; i < 4; i++) {
				if (isvalid(s.substr(0, i)) && s.size() >= i) {
					if (part == 3) helper(s.substr(i), out + s.substr(0, i), part + 1, res);
					else
						helper(s.substr(i), out + s.substr(0, i) + ".", part + 1, res);
				}
			}
		}
	}
	bool isvalid(string _str) {
		int _value = atoi(_str.c_str());
		if (_str.empty() || _str.size() > 3 || (_str.size() > 1 && _str[0] == '0') )
			return false;
		else
			return _value<=255 && _value >= 0;
	}
};

int longestsubstr(string s) {
	vector<bool> used(128, false);
	if (s.empty() )
		return 0;
	int start = 0, end = 0;
	//int count = 0;
	int _max = 0;	
	while (end < s.size())
	{
		if (used[s[end]]) {
			start++;
			used[s[end]] = false;
			//count = 0;
		}
		else {
			used[s[end]] = true;
			end++;
			//count++;
		}
		_max = max(end - start ,_max);
	}
	return _max;

}

int main()
{

	//string s = "aab";
	//Permute p;
	//vector<vector<string> >ans;
	//ans = p.partition(s);
	//for (auto X : ans){
	//	for (auto x : X){
	//		cout << x<<" ";
	//	}
	//	cout << endl;
	//}

	//string example
		
	//int a[] = { 10,1,2,7,6,1,5};
		//int b[] = {4,2,5,6,3,1};
		//string arr[] = {"eat", "tea", "tan", "ate", "nat", "bat"};
	//string s1 = "aaa";
	//string p = "a*a";
		//string s2 = "bab";
	//StringQuestions strsolve;
	//int m = strsolve.lengthOfLastWord(s1);
	//bool m = strsolve.isMatch(s1, p);
	//cout <<m<<endl;

	//vector example

	//int m = longestConsecutive(array2);
		//string a[2] = { "aba", "bca" };
	//int int_array[] = {2,7,11,5 };
		//vector<string> str(a, a + 2);
		//string s = longestCommonPrefix(str);
	//vector<int> i_arr(int_array, int_array + 4);
		//nextPermutation(i_arr);
		//for (int i = 0; i < i_arr.size(); i++)
		//	cout << i_arr[i] << endl;
		//int a[4][4] = { {2},{3,4},{6,5,7},{4,1,2,8}};
		//vector<vector<int> > arr(4, vector<int>(4));
		//arr[0].resize(1);
		//arr[1].resize(2);
		//arr[2].resize(3);
		//arr[3].resize(4);
		//
		//arr[0][0] = 2;
		//
		//arr[1][0] = 3;
		//arr[1][1] = 4;
		//
		//arr[2][0] = 6;
		//arr[2][1] = 5;
		//arr[2][2] = 7;
		//arr[3][0] = 4;
		//arr[3][1] = 1;
		//arr[3][2] = 8;
		//arr[3][3] = 3;
		//string s = "([})";
	//NumProblems np;
	//vector<int>ans = np.twoSum(i_arr,9);
	//cout << ans[0] <<"  "<<ans[1]<< endl;

	//ListNode example

	int a[] = { 3,5};
	ListNode *head = new ListNode(0);
	ListNode *pre = head;
	for (auto x :a) 
	{
		ListNode *p = new ListNode(x);
		pre->next = p;
		pre = p;
	}
	pre->next = NULL;
	
	LinkListSolve tempobject ;
	ListNode *ans = tempobject.reverseBetween(head->next, 1, 2);
	while (ans)
	{
		cout << ans->val <<  endl;
		ans = ans->next;
	}

	//DivideNConquer dnc;
	//string s = "25525511135";
	//vector<string>res;
	//res = dnc.restoreIpAddresses(s);
	//for (auto x : res) {
	//	cout << x << endl;
	//}
	cin.get();
	return 0;
}