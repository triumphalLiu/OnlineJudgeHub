#include "global.h"

class Solution {
	/*Question 52 正则表达式匹配
	*题目描述
	*	实现一个函数用来匹配包括'.'和'*'的正则表达式。模式中的字符'.'表示任意一个字符，而'*'表示它前面的字符可以出现任意次（包含0次）。 
	*	在本题中，匹配是指字符串的所有字符匹配整个模式。例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但是与"aa.a"和"ab*a"均不匹配
	*	时间限制：1秒 空间限制：32768K
	*思路描述
	*	动态规划
	*	if pattern[j] == str[i] || pattern[j] == '.'  then dp[i][j] = dp[i-1][j-1]
	*	if pattern[j] == '*' then
	*		if pattern[j-1] != str[i] && pattern[j-1] != '.' then dp[i][j] = dp[i][j-2]
	*		else dp[i][j] = dp[i][j-2] || dp[i][j-1] || dp[i-1][j]
	*/
public:
	bool match(char* str, char* pattern) {
		bool **dp = new bool*[strlen(str) + 1];
		for (int i = 0; i <= strlen(str); ++i) {
			dp[i] = new bool[strlen(pattern) + 1];
			memset(dp[i], 0, sizeof(bool) * (strlen(pattern) + 1));
		} 
		dp[0][0] = true;
		for (int j = 0; j < strlen(pattern); ++j) {
			if (pattern[j] == '*' && dp[0][j - 1])
				dp[0][j + 1] = true;
		}
		for (int i = 0; i < strlen(str); ++i) {
			for (int j = 0; j < strlen(pattern); ++j) {
				if (pattern[j] == str[i] || pattern[j] == '.')
					dp[i + 1][j + 1] = dp[i][j];
				else if (pattern[j] == '*') {
					if (pattern[j - 1] != str[i] && pattern[j - 1] != '.')
						dp[i + 1][j + 1] = dp[i + 1][j - 1];
					else
						dp[i + 1][j + 1] = dp[i + 1][j] || dp[i + 1][j - 1] || dp[i][j + 1];
				}
			}
		}
		return dp[strlen(str)][strlen(pattern)];
	}

	/*Use For Debug*/
	void Display(bool **arr, int a, int b) {
		for (int i = 0; i < a; ++i) {
			for (int j = 0; j < b; ++j) {
				cout << arr[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}

	int Debug() {
		char arr[4] = "aaa", p1[4] = "a.a", p2[8] = "ab*ac*a", p3[5] = "aa.a", p4[5] = "ab*a";
		char str[1] = "", s1[3] = ".*";
		assert(match(arr, p2) == true);
		return 0;
	}
};