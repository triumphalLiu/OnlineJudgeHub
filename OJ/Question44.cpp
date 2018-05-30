#include "global.h"

class Solution {
	/*Question 44 ��ת����˳����
	*��Ŀ����
	*	���磬�����ַ�����student. a am I������ȷ�ľ���Ӧ���ǡ�I am a student.����
	*	ʱ�����ƣ�1�� �ռ����ƣ�32768K
	*˼·����
	*	�ȷ�ת�����ַ������ٷ�תÿ�����ʡ�
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