#include "global.h"

class Solution {
	/*Question 41 ��ΪS��������������
	*��Ŀ����
	*	������к�ΪS�������������С������ڰ��մ�С�����˳�����м䰴�տ�ʼ���ִ�С�����˳�����С�
	*	ʱ�����ƣ�1�� �ռ����ƣ�32768K
	*˼·����
	*	�ⷨ1��ֱ�ӽⷽ�̣�i��0��sum/2����n��((i+1)+(i+n))*n/2=s��Ȼ���ж�n�Ƿ�������������ǣ����i+1��i+n���ӽ���������С������д������������㣬���Բ��Ǻܺõİ취��
	*	�ⷨ2��˫ָ��ⷨ��һ��ָ��ָ����࣬һ��ָ��ָ���Ҳ࣬��ͣ����С��sum�����Ҳ�ָ���һ���������ָ���һ,�������sum���򱣴�left��right��Щ����
	*/
public:
	vector<vector<int> > FindContinuousSequence_Way1(int sum) {
		vector<vector<int> > result;
		for (int i = 0; i < sum/2; ++i) {
			double n = ((sqrt(4 * i*(i + 1) + 1 + 8 * sum) - (2 * i + 1)) / 2);
			if (n - (int)n < 0.000001) {
				vector<int> temp;
				for (int j = i + 1; j < i + 1 + (int)n; ++j)
					temp.push_back(j);
				result.push_back(temp);
			}
		}
		return result;
	}

	vector<vector<int> > FindContinuousSequence(int sum) {
		vector<vector<int> > result;
		int left = 1, right = 2;
		while (right < sum) {
			int size = right - left + 1;
			int total = (left + right) * size / 2;
			if (total < sum)
				right += 1;
			else if (total > sum)
				left += 1;
			else {
				vector<int> temp;
				for (int i = left; i <= right; ++i)
					temp.push_back(i);
				result.push_back(temp);
				left += 1;
			}
		}
		return result;
	}

	/*Use For Debug*/
	int Debug() {
		vector<vector<int> > result = FindContinuousSequence(100);
		for (int i = 0; i < result.size(); ++i) {
			for (int j = 0; j < result[i].size(); ++j) {
				cout << result[i][j] << " ";
			}
			cout << endl;
		}
		return 0;
	}
};

int main() {
	Solution s;
	return s.Debug();
}