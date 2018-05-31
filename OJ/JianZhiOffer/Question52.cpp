#include "global.h"

class Solution {
	/*Question 52 ������ʽƥ��
	*��Ŀ����
	*	ʵ��һ����������ƥ�����'.'��'*'��������ʽ��ģʽ�е��ַ�'.'��ʾ����һ���ַ�����'*'��ʾ��ǰ����ַ����Գ�������Σ�����0�Σ��� 
	*	�ڱ����У�ƥ����ָ�ַ����������ַ�ƥ������ģʽ�����磬�ַ���"aaa"��ģʽ"a.a"��"ab*ac*a"ƥ�䣬������"aa.a"��"ab*a"����ƥ��
	*	ʱ�����ƣ�1�� �ռ����ƣ�32768K
	*˼·����
	*	��̬�滮
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