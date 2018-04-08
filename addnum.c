#include<stdio.h>
#include<math.h>
#include<stdlib.h>

typedef struct ListNode
{
	int val;
	struct ListNode *next;
}ListNode;

struct ListNode* addTwoNumbers(ListNode *l1, ListNode *l2);
ListNode * NewAdd(ListNode *l1, ListNode *l2);
int GetLength(ListNode *s);
ListNode * CreateList(ListNode *head);
long FetchNum(ListNode *s);
ListNode* Reverse(ListNode *s);
void PrintList(ListNode *head);

int main()
{
	ListNode *l1,*l2;
	ListNode *p,*r,*q, *ans;
	int temp = 0;
	l1 = (ListNode*)malloc(sizeof(ListNode));
	l2 = (ListNode*)malloc(sizeof(ListNode));
	printf("请输入第一组数（以-1结束输入）：\n");
	l1 = CreateList(l1);	
	printf("请输入第二组数，以 -1 结束输入 \n");
	l2 = CreateList(l2);
	//ans = addTwoNumbers(l1,l2);
	ans = NewAdd(l1, l2);
	PrintList(ans);
	return 0;
}

ListNode * CreateList(ListNode *head)
{
	int num;
	ListNode *p,*r = head;
	while(scanf("%d",&num)!=EOF)
	{
		if(num == -1)
		  break;
		p = (ListNode*)malloc(sizeof(ListNode));
		p->val = num;
		r->next = p;
		r = p;
	}
	r->next = NULL;
	return head;	
}

void PrintList(ListNode *head)
{
	ListNode *p;
	p = head->next;
	while(p)
	{
		printf("%d\n",p->val);
		p = p->next;
	}
}



int GetLength(ListNode *s)
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

long FetchNum(ListNode *s)
{
	long length;
	long ans = 0;
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

ListNode* Reverse(ListNode *s)
{
	ListNode *head,*p;
	head = (ListNode*)malloc(sizeof(ListNode));
	head->next = NULL;
	if(s==NULL||s->next == NULL)
		return s;
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


ListNode* addTwoNumbers(ListNode *l1, ListNode *l2)
{
	//fetch the num in the list and then put it back to the new list
	long I_sum,I_add1,I_add2;
	long I_value;
	ListNode *head,*p,*r;
	head = (ListNode*)malloc(sizeof(ListNode));
	r = head;
	//l1 = l1->next;
	I_add1 = FetchNum(Reverse(l1));
	I_add2 = FetchNum(Reverse(l2));
	
	I_sum = I_add1 + I_add2;
	
	while(I_sum)
	{	
		I_value = I_sum % 10 ;
                p = (ListNode*)malloc(sizeof(ListNode));
                p->val = I_value;
                r->next = p;
                r = p;
		I_sum = I_sum / 10 ;	
	}
	r->next = NULL;
	return head;
}

ListNode* NewAdd(ListNode *l1, ListNode *l2)
{
	ListNode*head,*p,*r;
	int extra = 0;
	head = (ListNode*)malloc(sizeof(ListNode));
	r = head;
	while(l1 || l2 || extra)
	{
		if(l1)
		{
		   extra += l1->val;
		   l1 = l1->next;
		}
		if(l2)
		{
		    extra += l2->val;
		    l2 = l2->next;
		}
		p = (ListNode*)malloc(sizeof(ListNode));
		p->val = extra % 10 ;
		extra = extra/10;
		r->next = p;
		r = p;
	}
	r->next = NULL;
	return head->next;
}

