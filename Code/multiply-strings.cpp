/*
	@43 Medium
	Multiply strings
	Given two non-negative integers num1 and num2 represented as strings, 
	return the product of num1 and num2, also represented as a string.
	author：paul
	date：
*/

#include <string>
#include <vector>
#include <climits>
#include <iostream>
using namespace std;

vector<string> singlemultiply(int lon, int shor,string lnum, string snum){
	vector<string> ansset;
	for(int i = shor - 1; i >= 0; i--){
		int c = 0;
		string ans = "";
		for(int j = lon - 1; j >= 0; j--){
			int tmp = (lnum[j] - '0') * (snum[i] - '0') + c;
			int mulans = tmp % 10;
			c = tmp / 10;
			ans.insert(ans.begin(), mulans + '0');
			if(j == 0 && c > 0)
				ans.insert(ans.begin(), c + '0');
		}
		int suffzero = shor - i - 1;
		while(suffzero != 0){
			ans.push_back('0');
            --suffzero;
		}
		//cout<< ans << endl; 
		ansset.push_back(ans);
	}
	return ansset;
}
/*
方法一:
简单模拟乘法逐位相乘的过程，然后将结果相加
注意大数的乘法，加法的模拟过程的进位问题即可
考虑 乘法中遇到 0 的情况
*/
string multiply_01(string num1, string num2) {
	int len1 = num1.size();
	int len2 = num2.size();
	vector<string> temp;
	if(len1 > len2){
		temp = singlemultiply(len1, len2, num1, num2);
	}
	else{
		temp = singlemultiply(len2, len1, num2, num1);
	}

    if(num1 == "0" || num2 == "0")
    	return "0";
    if(temp.size() == 1)
        return temp[0];
    int len = temp.size();
	int minlen = temp[0].size();
	int maxlen = temp[len - 1].size();

	string multiplyans = "";

	int c = 0;
	for(int i = 0; i < len; ++i){
		int prezero = maxlen - temp[i].size();
		while(prezero != 0){
			temp[i].insert(temp[i].begin(), '0');
			--prezero;
		}
	}
	for(int k = 0; k < maxlen; ++k){
		int sum = 0;
		for(int i = 0; i < len; ++i){
			int tmplen = temp[i].size();
			sum += temp[i][tmplen - k - 1] - '0';
		}
		sum += c;
		int tsum = sum  % 10;
		c = sum / 10;
		// cout<<"sum = "<<sum<<endl;
		// cout<<"c = "<<c<<endl;
		// cout<<"tsum = "<<tsum<<endl;
		multiplyans.insert(multiplyans.begin(), tsum + '0'); 
	}
	if(c>0) multiplyans.insert(multiplyans.begin(), c + '0');
	return multiplyans;
}

int main(){
	string num1 = "3";
	string num2 = "38";
	string ans = multiply(num1, num2);
	cout<< ans << endl;
	return 0;
}