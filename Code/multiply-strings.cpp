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
			int tmp = (lnum[j] - '0') * (snum[i] - '0');
			int mulans = tmp % 10 + c;
			c = tmp / 10;
			ans.insert(ans.begin(), mulans + '0');
			if(j == 0 && c > 0)
				ans.insert(ans.begin(), c + '0');
		}
		int zero = shor - i - 1;
		while(zero != 0){
			ans.push_back('0');
            zero--;
		}
		cout<< ans << endl; 
		ansset.push_back(ans);
	}
	return ansset;
}
string multiply(string num1, string num2) {
	int len1 = num1.size();
	int len2 = num2.size();
	vector<string> temp;
	if(len1 > len2){
		temp = singlemultiply(len1, len2, num1, num2);
	}
	else{
		temp = singlemultiply(len2, len1, num2, num1);
	}
    if(temp.size() == 1)
        return temp[0];
	int minlen = temp[0].size();
	int maxlen = temp[temp.size() - 1].size();

	string multiplyans = "";
	int c = 0;
	for(int k = 0; k < minlen; ++k){
		int sum = 0;
		for(int i = 0; i < temp.size(); ++i){
			int tmplen = temp[i].size();
			sum += temp[i][tmplen - k - 1] - '0';
		}
		cout<<"sum = "<<sum<<endl;
		int tsum = (sum + c) % 10;
		c = sum / 10;
		cout<<"c = "<<c<<endl;
		cout<<"tsum = "<<tsum<<endl;
		multiplyans.insert(multiplyans.begin(), tsum + '0');
	}
	int res = maxlen - minlen;
	int res_0 = temp[temp.size() - 1][res - 1] - '0' + c;
	//cout << "res_0 = " << res_0 <<endl;
	multiplyans.insert(multiplyans.begin(), res_0 + '0');
	for(int m = 0; m < res - 1; m++){
		multiplyans.insert(multiplyans.begin(), temp[temp.size() - 1][m]);
	}
	return multiplyans;
}

int main(){
	string num1 = "999";
	string num2 = "999";
	string ans = multiply(num1, num2);
	cout<< ans << endl;
	return 0;
}