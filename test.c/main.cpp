#include <iostream>
#include<math.h>
using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}

 struct ListNode {
      int val;
      struct ListNode *next;
 };



int GetLength(struct ListNode *s);
int FetchNum(struct ListNode *s);
struct ListNode* Reverse(struct ListNode *s);

int GetLength(struct ListNode *s)
{
	int count = 0;
	s = s->next;
	while(s)
	{
		count++;
		s = s->next;
	}
	return count;
}
int FetchNum(struct ListNode *s)
{
	int length;
	int ans = 0;
	length = GetLength(s);
	s = s->next;
	while(length)
	{
		ans += pow(10.0,length-1)*s->val;
		length--;
		s = s->next;
	}
	return ans;
}
struct ListNode* Reverse(struct ListNode *s)
{
	struct ListNode *head,*p;
	head = (struct ListNode*)malloc(sizeof(struct ListNode));
	head->next = NULL;
	if(s==NULL||s->next == NULL)
    {return s;}
	s = s->next;
	while(s)
	{
		p = s;
		s = s->next;
		p->next = head->next;
		head->next = p;
	}
	return head;
}
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    	//fetch the num in the list and then put it back to the new list
	int I_sum,I_add1,I_add2;
	int I_value;
	struct ListNode *head,*p,*r;
	head = (struct ListNode*)malloc(sizeof(struct ListNode));
	r = head;
	//l1 = l1->next;
	I_add1 = FetchNum(Reverse(l1));
	I_add2 = FetchNum(Reverse(l2));
	I_sum = I_add1 + I_add2;
	while(I_sum)
	{
		I_value = I_sum % 10 ;
        p = (struct ListNode*)malloc(sizeof(struct ListNode));
        p->val = I_value;
        r->next = p;
        r = p;
		I_sum = I_sum / 10 ;
	}
	r->next = NULL;
	return head;
}
