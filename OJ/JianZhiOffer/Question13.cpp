#include "global.h"

class Solution {
	/*Question 13 ��������˳��ʹ����λ��ż��ǰ��
	*��Ŀ����
	*	����һ���������飬ʵ��һ�����������������������ֵ�˳��
	*	ʹ�����е�����λ�������ǰ�벿�֣����е�ż��λ��λ������ĺ�벿�֣�����֤������������ż����ż��֮������λ�ò��䡣
	*	ʱ�����ƣ�1�� �ռ����ƣ�32768K
	*˼·����
	*	�ռ任ʱ�䣬����һ����vector����������array�������ż����������������в���array��ɾ����
	*	������ɺ󣬽����������ϲ������Ӷ�O(n)��������ѭ��n�Σ���������Ҫ2n��;
	*/
public:
	void reOrderArray(vector<int> &array) {
		vector<int> evenNums;
		for(int i = 0; i < array.size(); ++i) {
			if (array[i] % 2 == 0) {
				evenNums.push_back(array[i]);
				array.erase(array.begin() + i);
				--i;
			}
		}
		for (int i = 0; i < evenNums.size(); ++i)
			array.push_back(evenNums[i]);
	}
};