#include "global.h"

class Solution {
public:
	/*
	*��Ŀ����
	*	��һ����ά�����У�ÿһ�ж����մ����ҵ�����˳������ÿһ�ж����մ��ϵ��µ�����˳������
	*   �����һ������������������һ����ά�����һ���������ж��������Ƿ��и�������
	*	ʱ�����ƣ�1�� �ռ����ƣ�32768K
	*˼·����
	*	�����Ͻǿ�ʼ��飬���С��Ŀ�꣬�ͷ�����һ�У��������Ŀ�꣬�ͷ�����һ�У�Ȼ�����С��ľ�����б�����
	*/
	bool Find(int target, vector<vector<int> > array) {
		int col = array[0].size();
		for (int i = 0; i < array.size(); ++i) {
			for (int j = col - 1; j >= 0; --j) {
				if (array[i][j] == target)
					return true;
				else if (j == col - 1 && array[i][j] < target)
					break;
				else if (j == col - 1 && array[i][j] > target)
					j = (col -= 1);
			}
		}
		return false;
	}

	/*
	*��Ŀ����
	*	��ʵ��һ����������һ���ַ����еĿո��滻�ɡ�%20����
	*	���磬���ַ���ΪWe Are Happy.�򾭹��滻֮����ַ���ΪWe%20Are%20Happy��
	*	ʱ�����ƣ�1�� �ռ����ƣ�32768K
	*˼·����
	*	ͳ�ƿո���������ٴӺ���ǰ�����滻��
	*/
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