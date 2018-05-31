#include "global.h"

class Solution {
	/*Question 54 字符流中第一个不重复的字符
	*题目描述
	*	请实现一个函数用来找出字符流中第一个只出现一次的字符。例如，当从字符流中只读出前两个字符"go"时，第一个只出现一次的字符是"g"。
	*	当从该字符流中读出前六个字符“google"时，第一个只出现一次的字符是"l"。如果当前字符流没有存在出现一次的字符，返回#字符。
	*	时间限制：1秒 空间限制：32768K
	*思路描述
	*	使用一个队列来记录字符出现的顺序，再使用一个数组来记录出现此处（类似于哈希表，因为char类型最多256中，因此可以直接创建一个静态数组）
	*	然后通过遍历队列，通过匹配哈希表的值找到仅出现一次的值即可。
	*	此算法复杂度O(1)，因为最差情况只会循环256次。
	*/
private:
	unsigned int timesArray[256];
	queue<char> chArray;

public:
	//Insert one char from stringstream
	void Insert(char ch) {
		if (++timesArray[ch] == 1)
			chArray.push(ch);
	}
	//return the first appearence once char in current stringstream
	char FirstAppearingOnce() {
		while (timesArray[chArray.front()] != 1) {
			chArray.pop();
			if (chArray.empty())
				return '#';
		}
		return chArray.front();
	}

	Solution() {
		memset(timesArray, 0, sizeof(unsigned) * 256);
	}
};