#include "global.h"

class Solution {
	/*Question 2 �滻�ո�
	*��Ŀ����
	*	��ʵ��һ����������һ���ַ����еĿո��滻�ɡ�%20����
	*	���磬���ַ���ΪWe Are Happy.�򾭹��滻֮����ַ���ΪWe%20Are%20Happy��
	*	ʱ�����ƣ�1�� �ռ����ƣ�32768K
	*˼·����
	*	ͳ�ƿո���������ٴӺ���ǰ�����滻��
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