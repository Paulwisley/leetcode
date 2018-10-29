/*
	@43 Medium
	Multiply strings
	Given two non-negative integers num1 and num2 represented as strings, 
	return the product of num1 and num2, also represented as a string.
	author：paul
	date：
*/
#include <iostream>
#include <string>
#include <vector>
#include <climits>
using namespace std;

vector<string> singlemultiply(int lon, int shor,string lnum, string snum){
	vector<string> ansset;
	for(int i = shor - 1; i >= 0; i--){
		int c = 0;
		string ans = "";
		for(int j = lon - 1; j >= 0; j--){
			int tmp = (lnum[j] - '0') * (snum[i] - '0');
			int mulans = tmp % 10 + c;
			c = tmp / 10;
			ans.insert(ans.begin(), mulans + '0');
            int zero = lon - j - 1;
			while(zero != 0){
				ans.push_back('0');
                zero--;
			}
		}
		ansset.push_back(ans);
	}
	return ansset;
}
string multiply(string num1, string num2) {
	int len1 = num1.size();
	int len2 = num2.size();
	std::vector<string> temp;
	if(len1 > len2){
		temp = singlemultiply(len1, len2, num1, num2);
	}
	else{
		temp = singlemultiply(len2, len1, num2, num1);
	}
	int minlen = INT_MAX;
	for(string str : temp){
		if(str.size() < minlen)
			minlen = str.size();
	}
	string multiplyans = "";
	int c = 0;
	for(int k = 0; k < minlen; ++k){
		int sum = 0;
		for(int i = 0; i < temp.size(); ++i){
			int tmplen = temp[i].size();
			sum += temp[i][tmplen - k - 1] - '0';
		}
		int tsum = sum % 10 + c;
		c = sum / 10;
		multiplyans.insert(multiplyans.begin(), tsum + '0');
	}
	return multiplyans;
}

int main(){
	return 0;
}