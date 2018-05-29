#include "global.h"

class Solution {
	/*Question 30 ���������������
	*��Ŀ����
	*	�ڹ��ϵ�һάģʽʶ����,������Ҫ��������������������,������ȫΪ������ʱ��,����ܺý����
	*	����,��������а�������,�Ƿ�Ӧ�ð���ĳ������,�������Աߵ��������ֲ����أ�
	*	����:{6,-3,-2,7,-15,1,2,2},����������������Ϊ8(�ӵ�0����ʼ,����3��Ϊֹ)����᲻�ᱻ������ס��(�������ĳ���������1)
	*	ʱ�����ƣ�1�� �ռ����ƣ�32768K
	*˼·����
	*	ʱ�临�Ӷ�O(n)���������һ����֮���жϣ��ܺͱ�Ϊ����������Ϊ��һ�����Խ������ļ��㶼û�а�����
	*	��ӵ�ǰ�����¿�ʼ���㣬�����ܺ���Ϊ0+��ǰ����
	*	ÿ����һ���������ѵ�ǰ��ֵ�͵�ǰ�����ֵ���жԱȣ�ȡ���ֵ���档
	*/
public:
	int FindGreatestSumOfSubArray(vector<int> array) {
		if (array.size() == 0) return 0;
		int returnNum = INT_MIN, currSum = 0;
		for (int i = 0; i < array.size(); ++i) {
			if (currSum >= 0)
				currSum += array[i];
			else
				currSum = array[i];
			if (currSum > returnNum) {
				returnNum = currSum;
			}
		}
		return returnNum;
	}

	/*Use For Debug*/
	int Debug() {
		vector<int> arr = { 6,-3,-2,7,-15,1,2,2 };
		cout << FindGreatestSumOfSubArray(arr) << endl;
		return 0;
	}
};

int main() {
	Solution s;
	return s.Debug();
}