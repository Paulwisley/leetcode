/*
	@92. Reverse Linked List II  
	Medium
	Reverse a linked list from position m to n. Do it in one-pass.
	Note: 1 ≤ m ≤ n ≤ length of list.
	author：paul
	date:2018-10-17 0:15
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