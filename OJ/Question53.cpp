#include "global.h"

class Solution {
	/*Question 53 ��ʾ��ֵ���ַ���
	*��Ŀ����
	*	��ʵ��һ�����������ж��ַ����Ƿ��ʾ��ֵ������������С������
	*	���磬�ַ���"+100","5e2","-123","3.1416"��"-1E-16"����ʾ��ֵ�� ����"12e","1a3.14","1.2.3","+-5"��"12e+4.3"�����ǡ�
	*	ʱ�����ƣ�1�� �ռ����ƣ�32768K
	*˼·����
	*	һ������Ҫ��������������
	*	�Ӽ��ţ����û������e/E����ôֻ�ܳ���һ���ұ����ڵ�0λ���������e/E������������e/E֮��1λ��
	*	С���㣺ֻ�ܳ�����e/E֮ǰ�����ֻ����һλ��
	*	E/e��ֻ�ܳ���һ���Ҳ����ڵ�һλ���Һ��治�����ַ�����β��
	*	�������ţ����������0-9���������֡�
	*/
public:
	bool isNumeric(char* str) {
		if (strlen(str) == 0 || str[0] == 'E' || str[0] == 'e') return false;
		bool isAfterE = false, pointExist = false, flagExist = false;
		for (int i = 0; i < strlen(str); ++i) {
			if (str[i] == '+' || str[i] == '-') {
				if (isAfterE) {
					if (str[i - 1] != 'E' && str[i - 1] != 'e')
						return false;
				}
				else if (flagExist)
					return false;
				else if (!flagExist && i > 0)
					return false;
				flagExist = true;
			}
			else if (str[i] == '.') {
				if (isAfterE || pointExist)
					return false;
				pointExist = true;
			}
			else if (str[i] == 'E' || str[i] == 'e') {
				if (isAfterE || i == strlen(str) - 1)	
					return false;
				isAfterE = true;
			}
			else if(str[i] < '0' || str[i] > '9') 
				return false;
		}
		return true;
	}

	/*Use For Debug*/
	int Debug() {
		Solution s;
		char arr[4] = "1e2";
		cout << s.isNumeric(arr) << endl;
		return 0;
	}
};