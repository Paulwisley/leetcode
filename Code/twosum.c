#include<stdio.h>
#include<malloc.h>
#include<math.h>
#include<stdlib.h>

typedef struct HashNode
{
        int key;
        int val;
}HashNode; //自定义哈希结点

typedef struct HashMap
{
        int size;
        HashNode** storage;
} HashMap;


int *twosum(int *nums,int numsize,int target); //O(n)级别 两次循环遍历
int *twosum_hash(int *nums,int numsize,int target);//以空间换时间 借用hash思想 一次循环即结束查询
int *twosum_hashmap(int *nums,int numsize,int target);//使用hashmap 构造map结构体变量

HashMap * HashCreate(int size);
void HashDestroy(HashMap *hashmap);
void HashSet(HashMap *hashmap, int key, int value);
HashNode * HashGet(HashMap *hashmap, int value);


int main()
{
	int num;
	int *nums;
	int *ans;
	int i = 0;
	int target;
	ans = (int*)malloc(2*sizeof(int));
	nums = (int*)malloc(100*sizeof(int));
	printf("请输入目标值：");
	scanf("%d",&target);
	printf("请输入数组中元素，输入-1时结束输入：");
	while(scanf("%d",&num)!=EOF)
	{
		*(nums+i) = num;
		i++;
		if(num == -1)
	           break;
	}	
	ans = twosum_hashmap(nums,i,target);
	printf("%d,%d",ans[0],ans[1]);
	return 0;
}

int *twosum(int* nums, int numsize, int target)
{
	int i = 0;
	int j = 0;
	int I_temp;//用来暂存被目标减完剩下的数
	int *ans;//用来保存满足条件的数的下标
	ans = (int*)malloc(2*sizeof(int));
	for(i=0; i<numsize; i++)
  	{
		I_temp = target - nums[i];
		for(j=i; j<numsize; j++)
		{
			if(i==j||I_temp!=nums[j])//不允许同一个数使用两次
			{
			     continue;
			}
			else
			{
			    ans[0] = i;
			    ans[1] = j;
			    break;
			}
		}
	}
	return ans;
}

int *twosum_hash(int *nums, int numsize, int target)
{
	//先声明一个超大内存的数组，用来存储映射的键值，也就是下标。
	int I_Max[10000] = {0};
	int *select_num = I_Max + 5000;//使用指针类型 方便操作
	int I_temp; //用来暂存被目标减完剩下的数
	int i = 0;
	int *ans;
	ans = (int *)malloc(2*sizeof(int));
	for(i = 0; i<numsize; i++)
	{
		I_temp =  target - nums[i];
		if(select_num[I_temp]) //反向查找索引是否存在 存在便将对应键值赋给ans保存 
		{
		   ans[0] = i;
		   ans[1] = select_num[I_temp] - 1;
		   return ans ; 
		}
		else
		   select_num[nums[i]] = i+1;//记录每个被访问过的元素的位置 
		
	}	
	return NULL;
}

HashMap *HashCreate(int size)
{
	HashMap *hashmap = malloc(sizeof(HashMap));
	hashmap->size = size;
	hashmap->storage = calloc(size, sizeof(HashMap*));
	return hashmap;
}

void HashDestroy(HashMap *hashmap)
{
	HashNode* node;
	int hash = 0;
	while(hash < hashmap->size - 1)
	{
		node = hashmap->storage[hash];
		free(node);
		hash++;
	}
	free(hashmap);
	free(hashmap->storage);
}

void HashSet(HashMap *hashmap, int key, int value)
{
	HashNode *node;
	int hash;
	hash = abs(key) % hashmap->size;
	while((node = hashmap->storage[hash]))
	{
		if(hash < hashmap->size - 1)
		     hash++;
		else
		    hash = 0;
	}
	//find a proper place to set new node
	node = (HashNode*)malloc(sizeof(HashNode));
	node->key = key;
	node->val = value;
	hashmap->storage[hash] = node;
}

HashNode *HashGet(HashMap *hashmap, int key)
{
	HashNode *node;
	int hash = 0;
	hash = abs(key) % hashmap->size;
	while((node = hashmap->storage[hash]))
	{
		if(node->key == key)
	           return node;
		if(hash < hashmap->size - 1)
		    hash++;
		else
		    hash = 0;
	}
	return NULL;
}

int *twosum_hashmap(int *nums, int numsize, int target)
{
	int i;
	int I_Rest;//用来暂存待匹配数
	int *ans;
	ans = (int*)malloc(sizeof(int) * 2);
	HashMap * hashmap;
	HashNode *node;
	hashmap = HashCreate(numsize * 2);//HashMap大小取数组长度的两倍
	for(i=0; i<numsize; i++)
	{
		I_Rest = target - nums[i];
		node = HashGet(hashmap, I_Rest);
		if(node)
		{
			ans[0] = node->val;
			ans[1] = i;
			HashDestroy(hashmap);
			return ans;
		}
		else
		{
			HashSet(hashmap, nums[i], i);
		}	
	}
	return NULL;	
}



