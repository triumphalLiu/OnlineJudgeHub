#include "global.h"

class Solution {
	/*Question 34 第一个只出现一次的字符
	*题目描述
	*	在一个字符串(1<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,并返回它的位置。(没找到返回-1)
	*	时间限制：1秒 空间限制：32768K
	*思路描述
	*	先遍历一遍字符串并创建一个字典，把每个字母对应的次数保存起来。
	*	再遍历一遍字符串并核对字典，找出最早的且value为1的值。时间复杂度O(n)
	*/
public:
	int FirstNotRepeatingChar(string str) {
		map<char, int> charMap;
		for (int i = 0; i < str.length(); ++i) 
			charMap[str[i]]++;
		for (int i = 0; i < str.length(); ++i)
			if (charMap[str[i]] == 1)
				return i;
		return -1;
	}

	/*Use For Debug*/
	int Debug() {
		cout << FirstNotRepeatingChar("abcabcgefdfe") << endl;
		return 0;
	}
};