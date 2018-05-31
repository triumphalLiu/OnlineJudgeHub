#include "global.h"

class Solution {
	/*Question 43 ����ת�ַ���
	*��Ŀ����
	*	�����������һ����λָ�����ѭ�����ƣ�ROL���������и��򵥵����񣬾������ַ���ģ�����ָ�����������
	*	����һ���������ַ�����S���������ѭ������Kλ���������������磬�ַ�����S=��abcXYZdef��,Ҫ�����ѭ������3λ��Ľ��������XYZdefabc����
	*	ʱ�����ƣ�1�� �ռ����ƣ�32768K
	*˼·����
	*	XY=(X^T Y^T)^T  A^T��ʾA��ת�ã�A="ABC" A^T="CBA"
	*/
public:
	void reverseString(string &str, int begin, int end) {
		for (int i = 0; i < (end - begin + 1) / 2; ++i) {
			int temp = str[begin + i];
			str[begin + i] = str[end - i];
			str[end - i] = temp;
		}
	}

	string LeftRotateString(string str, int n) {
		if (str.length() <= 1) return str;
		n %= str.length();
		if (n == 0) return str;
		reverseString(str, 0, n-1);
		reverseString(str, n, str.length()-1);
		reverseString(str, 0, str.length()-1);
		return str;
	}

	/*Use For Debug*/
	int Debug() {
		cout << LeftRotateString("abcXYZdef", 3) << endl;
		return 0;
	}
};