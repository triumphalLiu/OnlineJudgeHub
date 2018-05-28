#include "global.h"

class Solution {
	/*Question 19 ˳ʱ���ӡ����
	*��Ŀ����
	*	����һ�����󣬰��մ���������˳ʱ���˳�����δ�ӡ��ÿһ�����֣�
	*	���磬����������¾��� 1 2 3 4/5 6 7 8/9 10 11 12/13 14 15 16 
	*	�����δ�ӡ������1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
	*	ʱ�����ƣ�1�� �ռ����ƣ�32768K
	*˼·����
	*	ֻ��Ҫ����i��j����������ת��ʱ������circleTime������������ǰ�Ѿ�����������������currentDirection����¼��ǰ������
	*	Hint:��̳���������ħ����ת��{{1,2,3},{4,5,6},{7,8,9}}ÿ�������ɾ����һ�к�{{4,5,6},{7,8,9}}������ȫ����ʱ����ת��{{6,9},{5,8},{4,7}}���ظ���������ֱ������Ϊ�ա�
	*/
public:
	vector<int> printMatrix(vector<vector<int> > matrix) {
		vector<int> result;
		if (matrix.size() == 0)
			return result;
		int row = matrix.size(), col = matrix[0].size();
		int sum = row * col;
		int circleTime = 0;
		int currentDirection = 0; //0 right, 1 left, 2 up, 3 down
		for (int i = 0, j = 0; result.size() < sum;) {
			result.push_back(matrix[i][j]);
			if (currentDirection == 0) {
				if (j == col - 1 - circleTime) {
					currentDirection = 3;
					i++;
				}
				else j++;
			}
			else if (currentDirection == 1) {
				if (j == circleTime) {
					currentDirection = 2;
					i--;
				}
				else j--;
			}
			else if (currentDirection == 2) {
				if(i - 1 == circleTime)
					circleTime++;
				if (i == circleTime) {
					currentDirection = 0;
					j++;
				}
				else i--;
			}
			else if (currentDirection == 3) {
				if (i == row - 1 - circleTime) {
					currentDirection = 1;
					j--;
				}
				else i++;
			}
		}
		return result;
	}

	/*Use For Debug*/
	int Debug() {
		vector<vector<int> > matrix = { { 1,2,3,4 },{ 5,6,7,8 },{ 9,10,11,12 },{ 13,14,15,16 } };
		Solution s;
		vector<int> v = s.printMatrix(matrix);
		for (int i = 0; i < v.size(); ++i)
			cout << v[i] << " ";
		cout << endl;
		return 0;
	}
};