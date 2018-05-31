#include "global.h"

class Solution {
	/*Question 42 ��ΪS����������
	*��Ŀ����
	*	����һ����������������һ������S���������в������������ǵ����ǵĺ�������S������ж�����ֵĺ͵���S������������ĳ˻���С�ġ�
	*	ʱ�����ƣ�1�� �ռ����ƣ�32768K
	*˼·����
	*	˫ָ�뷨�ı�ʽ����ָ��ָ����࣬��ָ��ָ���Ҳࣻ�������ȣ���ֱ�ӷ��أ���Ϊһ������С�ĳ˻������������sum������ָ�����ƣ����С��sum������ָ�����ƣ�ֱ����ָ�뽻�㣬����<��>��
	*/
public:
	vector<int> FindNumbersWithSum(vector<int> array, int sum) {
		if (array.size() < 2) return {};
		int left = 0, right = array.size() - 1;
		vector<int> result;
		while (left != right) {
			int value = array[left] + array[right];
			if (value == sum) {
				result.push_back(array[left]);
				result.push_back(array[right]);
				break;
			}
			else if (value > sum) {
				right--;
			}
			else if (value < sum) {
				left++;
			}
		}
		return result;
	}

	/*Use For Debug*/
	int Debug() {
		vector<int> temp = FindNumbersWithSum({1,2,3,4,5,6,7,8}, 8);
		cout << temp[0] << " " << temp[1] << endl;
		return 0;
	}
};