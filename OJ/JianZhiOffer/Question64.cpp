#include "global.h"

class Solution {
	/*Question 64 �������ڵ����ֵ
	*��Ŀ����
	*	����һ������ͻ������ڵĴ�С���ҳ����л�����������ֵ�����ֵ�����磬�����������{2,3,4,2,6,2,5,1}���������ڵĴ�С3��
	*	��ôһ������6���������ڣ����ǵ����ֵ�ֱ�Ϊ{4,4,6,6,6,5}�� �������{2,3,4,2,6,2,5,1}�Ļ�������������6���� 
	*	{[2,3,4],2,6,2,5,1}�� {2,[3,4,2],6,2,5,1}�� {2,3,[4,2,6],2,5,1}�� {2,3,4,[2,6,2],5,1}�� {2,3,4,2,[6,2,5],1}�� {2,3,4,2,6,[2,5,1]}��
	*	ʱ�����ƣ�1�� �ռ����ƣ�32768K
	*˼·����
	*	���ȶ��ڴ��ڳ��ȴ�����������������ֱ���ҵ����ֵ���ؼ��ɡ�
	*	�����������������ָ�룬һ��ָ�򴰿���࣬һ��ָ�򴰿��Ҳ࣬���ҵ���һ�ε����ֵ��
	*	��󴰿ڻ�������黬��ǰ������ֵ�Ƿ�������ֵ������ǣ�����ѡȡ���ֵ��Ȼ�����ֵ�ͻ�������Ҳ�ָ���ֵ���жԱȣ�ȡ��ġ�
	*/
public:
	vector<int> maxInWindows(const vector<int>& num, unsigned int size)	{
		if (size == 0 || num.size() < size) return {};
		else if (num.size() == size) {
			int max = INT_MIN;
			for (int i = 0; i < num.size(); ++i)
				if (num[i] > max)
					max = num[i];
			return { max };
		}
		else {
			vector<int> result;
			int left = 0, right = size - 1, currMax = INT_MIN;
			/* �ҵ���һ�ε����ֵ */
			for (int i = left; i <= right; ++i)
				if (num[i] > currMax)
					currMax = num[i];
			result.push_back(currMax);
			/* ���ڽ��л��� */
			while (true) {
				if (num[left] == currMax) {
					currMax = INT_MIN;
					for (int i = left + 1; i <= right; ++i)
						if (num[i] > currMax)
							currMax = num[i];
				}
				++left; ++right;
				if (right == num.size()) break;
				if (num[right] > currMax)
					currMax = num[right];
				result.push_back(currMax);
			}
			return result;
		}
	}
};