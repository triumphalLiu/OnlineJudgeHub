#include "global.h"

class Solution {
	/*Question 65 �����е�·��
	*��Ŀ����
	*	�����һ�������������ж���һ���������Ƿ����һ������ĳ�ַ��������ַ���·����·�����ԴӾ����е�����һ�����ӿ�ʼ��ÿһ�������ھ������������ң����ϣ������ƶ�һ�����ӡ�
	*	���һ��·�������˾����е�ĳһ�����ӣ����·�������ٽ���ø��ӡ� 
	*	���� a b c e s f c s a d e e �����а���һ���ַ���"bcced"��·�������Ǿ����в�����"abcb"·������Ϊ�ַ����ĵ�һ���ַ�bռ���˾����еĵ�һ�еڶ�������֮��·�������ٴν���ø��ӡ�
	*	ʱ�����ƣ�1�� �ռ����ƣ�32768K
	*˼·����
	*	���ݷ�����ÿ���㿪ʼ�����ĸ��������ƶ�����������Ҫ�������һ��������������롣
	*	Hint������Ҫ������bool�����ʹ�ã����ʧ�ܣ���Ҫ����ǰ���true�ı�־λ���false��
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