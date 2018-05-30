#include "global.h"

class Solution {
	/*Question 45 ��ת����˳����
	*��Ŀ����
	*	��һ���˿��ƣ����������С������С��(0)���Կ����κ�����,����A����1,JΪ11,QΪ12,KΪ13���ж��������ǲ���˳�ӡ�
	*	ʱ�����ƣ�1�� �ռ����ƣ�32768K
	*˼·����
	*	�ȶ����������������ͳ��0�ĸ�����������������һ�����ֽ��жԱȣ�
	*	�����ȣ�һ������˳�ӣ����0�ĸ�����ȥ����֮˳�Ӳ11��13��˳�Ӳ�Ϊ1��11��12˳�Ӳ�Ϊ0���Ǹ����������������������˻��ǲ������˳�ӣ�����ôһ������˳�ӡ�
	*	�������˳�ӡ�
	*/
public:
	bool IsContinuous(vector<int> numbers) {
		if (numbers.size() == 0) return false;
		sort(numbers.begin(), numbers.end());
		int zeroCount = 0, lastNum = -1;
		for (int i = 0; i < numbers.size(); ++i) {
			if (numbers[i] == 0)
				++zeroCount;
			else if (lastNum == -1)
				lastNum = numbers[i];
			else {
				if (lastNum == numbers[i])
					return false;
				zeroCount -= (numbers[i] - lastNum - 1);
				lastNum = numbers[i];
				if (zeroCount < 0)
					return false;
			}
		}
		return true;
	}

	/*Use For Debug*/
	int Debug() {
		cout << IsContinuous({ 0,3,5,7,0 }) << endl;
		return 0;
	}
};

int main() {
	Solution s;
	return s.Debug();
}