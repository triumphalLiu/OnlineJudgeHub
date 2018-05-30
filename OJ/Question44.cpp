#include "global.h"

class Solution {
	/*Question 44 翻转单词顺序列
	*题目描述
	*	例如，对于字符串“student. a am I”，正确的句子应该是“I am a student.”。
	*	时间限制：1秒 空间限制：32768K
	*思路描述
	*	先翻转整个字符串，再翻转每个单词。
	*/
public:
	void reverseString(string &str, int begin, int end) {
		for (int i = 0; i < (end - begin + 1) / 2; ++i) {
			int temp = str[begin + i];
			str[begin + i] = str[end - i];
			str[end - i] = temp;
		}
	}

	string ReverseSentence(string str) {
		reverseString(str, 0, str.length() - 1);
		int left = 0, right = 0, isInAWord = 0;
		for (int i = 0; i < str.length(); ++i) {
			if (str[i] == ' ' || i == str.length() - 1) {
				if (isInAWord) {
					right = i - 1;
					if (i == str.length() - 1)
						right += 1;
					reverseString(str, left, right);
				}
				isInAWord = 0;
			}
			else {
				if (!isInAWord)
					left = i;
				isInAWord = 1;
			}
		}
		return str;
	}

	/*Use For Debug*/
	int Debug() {
		cout << ReverseSentence("c abcXYZdef a") << endl;
		return 0;
	}
};