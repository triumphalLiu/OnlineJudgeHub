#include "global.h"

class Solution {
	/*Question 40 数组中只出现一次的数字
	*题目描述
	*	一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字。
	*	时间限制：1秒 空间限制：32768K
	*思路描述
	*	由于相同的两个数异或的结果为0，那么对全部数字进行异或运算后得到的结果就是两个目标数字的异或结果。
	*	找出异或结果的1的最低出现位，就是两个数不同的位，然后将原数组此位为1或者0而分成两组，
	*	分别再次异或，就得到了两个只出现过一次的数字。
	*	Hint: 除以2的n次方可以用右移，模2可以用&1
	*/
public:
	void FindNumsAppearOnce(vector<int> data, int* num1, int *num2) {
		int allExOrResult = 0;
		for (int i = 0; i < data.size(); ++i)
			allExOrResult ^= data[i];
		int index = 1;
		while (!(allExOrResult & 1)) {
			++index;
			allExOrResult >>= 1;
		}
		vector<int> dataSet1, dataSet2;
		for (int i = 0; i < data.size(); ++i) {
			if ((data[i] >> (index - 1)) & 1)
				dataSet1.push_back(data[i]);
			else
				dataSet2.push_back(data[i]);
		}
		int number1 = 0, number2 = 0;
		for (int i = 0; i < dataSet1.size(); ++i)
			number1 ^= dataSet1[i];
		for (int i = 0; i < dataSet2.size(); ++i)
			number2 ^= dataSet2[i];
		num1[0] = number1;
		num2[0] = number2;
	}
};