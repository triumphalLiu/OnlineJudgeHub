#include "global.h"

class Solution {
	/*Question 65 矩阵中的路径
	*题目描述
	*	请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。路径可以从矩阵中的任意一个格子开始，每一步可以在矩阵中向左，向右，向上，向下移动一个格子。
	*	如果一条路径经过了矩阵中的某一个格子，则该路径不能再进入该格子。 
	*	例如 a b c e s f c s a d e e 矩阵中包含一条字符串"bcced"的路径，但是矩阵中不包含"abcb"路径，因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入该格子。
	*	时间限制：1秒 空间限制：32768K
	*思路描述
	*	回溯法，从每个点开始，向四个方向尝试移动，若不满足要求，则回溯一步，否则继续深入。
	*	Hint：本题要点在于bool数组的使用，如果失败，需要将当前变成true的标志位变回false。
	*/
public:
	bool hasPath(char* matrix, int rows, int cols, char* str) {
		if (str == NULL || strlen(str) == 0 || matrix == NULL || strlen(matrix) == 0) return false;
		bool *visitedFlag = new bool[rows * cols];
		memset(visitedFlag, 0, sizeof(bool) * (rows * cols));
		for (int i = 0; i < rows; ++i)
			for (int j = 0; j < cols; ++j)
				if (canMove(i, j, matrix, str, visitedFlag, rows, cols))
					return true;
		return false;
	}

	bool canMove(int currX, int currY, char *matrix, char *str, bool *visited, int rows, int cols) {
		if (strlen(str) == 0) return true;
		if (currX < 0 || currX >= rows || currY < 0 || currY >= cols || visited[currX * cols + currY] || matrix[currX * cols + currY] != str[0]) 
			return false;
		visited[currX * cols + currY] = true;
		if (canMove(currX, currY - 1, matrix, str + 1, visited, rows, cols) || canMove(currX, currY + 1, matrix, str + 1, visited, rows, cols)
			|| canMove(currX - 1, currY, matrix, str + 1, visited, rows, cols) || canMove(currX + 1, currY, matrix, str + 1, visited, rows, cols))
			return true;
		else {
			visited[currX * cols + currY] = false;
			return false;
		}
	}

	/* Use For Debug */
	int Debug() {
		char arr[13] = "ABCESFCSADEE", str[7] = "ABCCED";
		cout << hasPath(arr, 3, 4, str) << endl;
		return 0;
	}
};