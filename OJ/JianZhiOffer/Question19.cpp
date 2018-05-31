#include "global.h"

class Solution {
	/*Question 19 顺时针打印矩阵
	*题目描述
	*	输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，
	*	例如，如果输入如下矩阵： 1 2 3 4/5 6 7 8/9 10 11 12/13 14 15 16 
	*	则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
	*	时间限制：1秒 空间限制：32768K
	*思路描述
	*	只需要控制i，j两个参数的转向时机，用circleTime变量来计数当前已经遍历的周期数，用currentDirection来记录当前的走向。
	*	Hint:论坛中有人提出魔方旋转，{{1,2,3},{4,5,6},{7,8,9}}每次输出并删除第一行后，{{4,5,6},{7,8,9}}将矩阵全部逆时针旋转，{{6,9},{5,8},{4,7}}。重复上述操作直到矩阵为空。
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