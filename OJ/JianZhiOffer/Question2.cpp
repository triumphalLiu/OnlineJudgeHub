#include "global.h"

class Solution {
	/*Question 2 替换空格
	*题目描述
	*	请实现一个函数，将一个字符串中的空格替换成“%20”。
	*	例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
	*	时间限制：1秒 空间限制：32768K
	*思路描述
	*	统计空格的数量，再从后往前进行替换。
	*/
public:
	void replaceSpace(char *str, int length) {
		int spaceCount = 0;
		for (int i = 0; i < length; ++i)
			if (str[i] == ' ')
				spaceCount++;
		int newLen = spaceCount * 2 + length;
		str[newLen] = '\0';
		for (int i = length - 1; i >= 0; --i) {
			if (str[i] != ' ')
				str[i + spaceCount * 2] = str[i];
			else if (str[i] == ' ') {
				str[i + spaceCount * 2] = '0';
				str[i + spaceCount * 2 - 1] = '2';
				str[i + spaceCount * 2 - 2] = '%';
				spaceCount--;
			}
		}
	}
};