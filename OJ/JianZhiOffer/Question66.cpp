#include "global.h"

class Solution {
	/*Question 66 �����˵��˶���Χ
	*��Ŀ����
	*	������һ��m�к�n�еķ���һ�������˴�����0,0�ĸ��ӿ�ʼ�ƶ���ÿһ��ֻ�������ң��ϣ����ĸ������ƶ�һ�񣬵��ǲ��ܽ�������������������λ֮�ʹ���k�ĸ��ӡ�
	*	���磬��kΪ18ʱ���������ܹ����뷽��35,37������Ϊ3+5+3+7 = 18�����ǣ������ܽ��뷽��35,38������Ϊ3+5+3+8 = 19�����ʸû������ܹ��ﵽ���ٸ����ӣ�
	*	ʱ�����ƣ�1�� �ռ����ƣ�32768K
	*˼·����
	*	ģ���н�����һ��bool��������ʾĳһ���Ƿ�����ߣ�Ȼ�����ĸ�����ݹ飬���ؿ��Ե���ķ��飬���У�ÿһ��������ķ���ȫ�������ٴξ�����
	*	Note:�����ߵ�����һ������ͨ�ģ���˲��ܼ�������ѭ���������еĵ㡣
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