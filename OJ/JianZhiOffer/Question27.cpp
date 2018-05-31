#include "global.h"

class Solution {
	/*Question 27 字符串的排列
	*题目描述
	*	输入一个字符串,长度不超过9(可能有字符重复),字符只包括大小写字母,按字典序打印出该字符串中字符的所有排列。
	*	例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
	*	时间限制：1秒 空间限制：32768K
	*思路描述
	*	迭代法：
	*	首先从后往前找到一个比后一个字符小的字符x，当找不到时退出。 如acb即a  
	*	然后从上述字符x往后找到一个连续且最后的且比其大的字符y。如acb即b
	*	然后交换字符x和字符y的位置。 上述变成bca
	*	然后将字符y新位置后面的字符串倒序排列。 上述变成bac
	*/
public:
	vector<string> Permutation(string str) {
		vector<string> result;
		if (str.length() == 0) return result;
		sort(str.begin(), str.end());
		result.push_back(str);
		if (str.length() == 1) return result;
		while (1) {
			int charLess = str.length() - 1;
			while (!(str[charLess - 1] < str[charLess])) {
				charLess -= 1;
				if (charLess == 0)
					return result;
			}
			charLess -= 1;
			int charLarger = charLess + 1; 
			while (charLarger < str.length() && str[charLarger] > str[charLess]) 
				charLarger++;
			charLarger -= 1;
			char temp = str[charLess];
			str[charLess] = str[charLarger];
			str[charLarger] = temp;
			for (int i = charLess + 1; i < (str.length() + charLess + 1) / 2; ++i) {
				temp = str[i];
				str[i] = str[str.length() + (charLess + 1) - i - 1];
				str[str.length() + (charLess + 1) - i - 1] = temp;
			}
			result.push_back(str);
		}
		return result;
	}

	/*Use For Debug*/
	int Debug() {
		string str = "abc";
		vector<string> result = Permutation(str);
		for (int i = 0; i < result.size(); ++i)
			cout << result[i].c_str() << endl;
		return 0;
	}
};