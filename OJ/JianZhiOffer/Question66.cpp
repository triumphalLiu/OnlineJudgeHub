#include "global.h"

class Solution {
	/*Question 66 机器人的运动范围
	*题目描述
	*	地上有一个m行和n列的方格。一个机器人从坐标0,0的格子开始移动，每一次只能向左，右，上，下四个方向移动一格，但是不能进入行坐标和列坐标的数位之和大于k的格子。
	*	例如，当k为18时，机器人能够进入方格（35,37），因为3+5+3+7 = 18。但是，它不能进入方格（35,38），因为3+5+3+8 = 19。请问该机器人能够达到多少个格子？
	*	时间限制：1秒 空间限制：32768K
	*思路描述
	*	模拟行进，用一个bool数组来表示某一点是否可以走，然后向四个方向递归，返回可以到达的方块，其中，每一个到达过的方块全都不能再次经过。
	*	Note:可以走的区域不一定是连通的，因此不能简单用两个循环遍历所有的点。
	*/
public:
	int movingCount(int threshold, int rows, int cols) {
		if (rows <= 0 || cols <= 0) return 0;
		bool *visitedFlag = new bool[rows * cols];
		memset(visitedFlag, 0, sizeof(bool) * rows * cols);
		for (int i = 0; i < rows; ++i)
			for (int j = 0; j < cols; ++j)
				if (calculateBitSum(i, j) > threshold)
					visitedFlag[i*cols + j] = true;
		return tryMove(rows, cols, 0, 0, visitedFlag);
	}

	int tryMove(int rows, int cols, int currX, int currY, bool *visitedFlag) {
		if (currX < 0 || currY < 0 || currX >= rows || currY >= cols || visitedFlag[currX*cols + currY]) return 0;
		visitedFlag[currX*cols + currY] = true;
		return 1 + tryMove(rows, cols, currX - 1, currY, visitedFlag) + tryMove(rows, cols, currX + 1, currY, visitedFlag) 
			+ tryMove(rows, cols, currX, currY - 1, visitedFlag) + tryMove(rows, cols, currX, currY + 1, visitedFlag);
	}

	int calculateBitSum(int a, int b) {
		int sum = 0;
		while (a != 0 || b != 0) {
			sum += a % 10;
			sum += b % 10;
			a /= 10;
			b /= 10;
		}
		return sum;
	}

	/* Use For Debug*/
	int Debug() {
		cout << movingCount(10, 10, 10) << endl;
		return 0;
	}
};