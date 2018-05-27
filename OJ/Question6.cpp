#include "global.h"

class Solution {
	/*Question 6 ��ת�������С����
	*��Ŀ����
	*	��һ�������ʼ�����ɸ�Ԫ�ذᵽ�����ĩβ�����ǳ�֮Ϊ�������ת�� ����һ���ǵݼ�����������һ����ת�������ת�������СԪ�ء� 
	*	��������{3,4,5,1,2}Ϊ{1,2,3,4,5}��һ����ת�����������СֵΪ1�� 
	*	NOTE������������Ԫ�ض�����0���������СΪ0���뷵��0��
	*	ʱ�����ƣ�3�� �ռ����ƣ�32768K
	*˼·����
	*	���ж���ʽ�µ�ʱ��Ϊ���󣬷��򷵻ص�һ������
	*/
public:
	int minNumberInRotateArray(vector<int> rotateArray) {
		if (rotateArray.size() <= 0)
			return 0;
		for (int i = 1; i < rotateArray.size(); ++i) {
			if (rotateArray[i] < rotateArray[i - 1])
				return rotateArray[i];
		}
		return rotateArray[0];
	}
};