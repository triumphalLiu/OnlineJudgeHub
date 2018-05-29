#include "global.h"

class Solution {
	/*Question 32 把数组排成最小的数
	*题目描述
	*	输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
	*	例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。。
	*	时间限制：1秒 空间限制：32768K
	*思路描述
	*	将相邻的两个数拼接并按照字符串的规则比较大小，把小的放在前面。最后统一拼接。
	*	Hint:可使用stl函数sort(a,b,function)，但function必须为static的;
	*	Hint:to_string(...) 在头文件<sstream>里
	*/
public:
	string PrintMinNumber(vector<int> numbers) {
		for (int i = 0; i < numbers.size(); ++i) {
			for (int j = 1; j < numbers.size(); ++j) {
				int a = numbers[j - 1], b = numbers[j];
				string arrA = to_string(a);
				arrA += to_string(b);
				string arrB = to_string(b);
				arrB += to_string(a);
				if (arrA > arrB) {
					int temp = numbers[j - 1];
					numbers[j - 1] = numbers[j];
					numbers[j] = temp;
				}
			}
		}
		string result = "";
		for (int i = 0; i < numbers.size(); ++i)
			result += to_string(numbers[i]);
		return result;
	}
};