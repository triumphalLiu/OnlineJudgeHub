#include "global.h"

class Solution {
	/*Question 1
	*��Ŀ����
	*	��һ����ά�����У�ÿһ�ж����մ����ҵ�����˳������ÿһ�ж����մ��ϵ��µ�����˳������
	*   �����һ������������������һ����ά�����һ���������ж��������Ƿ��и�������
	*	ʱ�����ƣ�1�� �ռ����ƣ�32768K
	*˼·����
	*	�����Ͻǿ�ʼ��飬���С��Ŀ�꣬�ͷ�����һ�У��������Ŀ�꣬�ͷ�����һ�У�Ȼ�����С��ľ�����б�����
	*/
public:
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
};