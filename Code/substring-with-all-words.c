/*********************
@30  Hard
SubString with concatennation of all words
author: paul
time: 2018-9-24 11：27
**********************/

#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;
vector<int> findSubstring(string S, vector<string> &L) 
{
		vector<int>indices;	
		unordered_map<string,int> count; //count the word num
		for(word:L){
			count[word]++;
		}
		int s_len = S.size();
		int num = L.size();
		int w_len = L[0].size();
		for(int i = 0; i < s_len - w_len * num + 1; i++ )
		{
			unordered_map<string,int> seen;//check the word if visited
			int j = 0;
			for(; j < num; j++ )
			{
				string word = S.substr(i + j * w_len  );		 
			}
		}        
}

