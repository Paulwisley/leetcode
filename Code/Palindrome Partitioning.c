/*********************
@131  Medium
Palindrome Partitioning：
	Given a string s, partition s such that every substring of the partition is a palindrome.
	Return all possible palindrome partitioning of s
author: paul
time: 2018-10-16 13:14
**********************/
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