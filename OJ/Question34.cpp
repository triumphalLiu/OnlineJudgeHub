#include "global.h"

class Solution {
	/*Question 34 ��һ��ֻ����һ�ε��ַ�
	*��Ŀ����
	*	��һ���ַ���(1<=�ַ�������<=10000��ȫ������ĸ���)���ҵ���һ��ֻ����һ�ε��ַ�,����������λ�á�(û�ҵ�����-1)
	*	ʱ�����ƣ�1�� �ռ����ƣ�32768K
	*˼·����
	*	�ȱ���һ���ַ���������һ���ֵ䣬��ÿ����ĸ��Ӧ�Ĵ�������������
	*	�ٱ���һ���ַ������˶��ֵ䣬�ҳ��������valueΪ1��ֵ��ʱ�临�Ӷ�O(n)
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