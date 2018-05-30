#include "global.h"

class Solution {
	/*Question 37 ���������������г��ֵĴ���
	*��Ŀ����
	*	ͳ��һ�����������������г��ֵĴ�����
	*	ʱ�����ƣ�1�� �ռ����ƣ�32768K
	*˼·����
	*	���ֲ��ң��ҳ�k+1��kӦ�ò����λ�ã�������ͬ���֣��������ͬ���ֵ���ǰ�棩��Ȼ��������ɡ�
	*/
public:
	int GetNumberOfK(vector<int> data, int k) {
		if (data.size() == 0) return 0;
		return binarySearch(data, k + 1) - binarySearch(data, k);
	}

	int binarySearch(vector<int> data, int num) {
		int min = 0, max = data.size() - 1;
		while (min <= max) {
			int mid = ((min + max) >> 1);
			if (data[mid] < num)
				min = mid + 1;
			else if (data[mid] >= num)
				max = mid - 1;
		}
		return min;
	}

	/*Use For Debug*/
	int Debug() {
		cout << GetNumberOfK({ 1,2,3,3,3,4 }, 0) << endl;
		return 0;
	}
};