#include "global.h"

class Solution {
	/*Question 28 �����г��ִ�������һ�������
	*��Ŀ����
	*	��������һ�����ֳ��ֵĴ����������鳤�ȵ�һ�룬���ҳ�������֡�
	*	��������һ������Ϊ9������{1,2,3,2,2,2,5,4,2}����������2�������г�����5�Σ��������鳤�ȵ�һ�룬������2����������������0��
	*	ʱ�����ƣ�1�� �ռ����ƣ�32768K
	*˼·����
	*	��Ȼ�����ֳ��ֵĴ�������һ�룬��ô����ɾ������������ͬ�����֣�ֱ�����ȫ��ɾ��(������)����ȫ��ʣ��һЩ��ͬ�����ּ�Ϊ����
	*	Note:��ֻ��һ�����ֻ�������Ϊ�յ�ʱ��Ӧ���������⴦��������Ϊ���������ֻ�����һλ��0��ʱ��ҲӦ���⴦��
	*/
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		if (numbers.size() == 0) return 0;
		if (numbers.size() == 1) return numbers[0];
		for (int i = 1; i < numbers.size(); ++i) {
			if (numbers[i] == 0)
				continue;
			if (numbers[i] != numbers[i - 1] && numbers[i - 1] != 0) {
				numbers[i] = numbers[i - 1] = 0;
			}
		}
		for (int i = 0; i < numbers.size(); ++i) {
			if ((numbers.size() & 1) && i == numbers.size() - 1)
				return 0;
			if (numbers[i] != 0)
				return numbers[i];
		}
		return 0;
	}

	/*Use For Debug*/
	int Debug() {
		vector<int> nums = { 1,2,3,2,2,2,5,4,2 };
		vector<int> nums2 = { 2,2,2,2,2,2,2,2,2 };
		vector<int> nums3 = { 1,2,3,2,4,2,5,2,3 };
		cout << MoreThanHalfNum_Solution(nums3) << endl;
		return 0;
	}
};