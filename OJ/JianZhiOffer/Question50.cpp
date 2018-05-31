#include "global.h"

class Solution {
	/*Question 50 �������ظ�������
	*��Ŀ����
	*	��һ������Ϊn����������������ֶ���0��n-1�ķ�Χ�ڡ�������ĳЩ�������ظ��ģ�����֪���м����������ظ��ġ�Ҳ��֪��ÿ�������ظ����Ρ����ҳ�����������һ���ظ������֡� 
	*	���磬������볤��Ϊ7������{2,3,1,0,2,5,3}����ô��Ӧ������ǵ�һ���ظ�������2��
	*	ʱ�����ƣ�1�� �ռ����ƣ�32768K
	*˼·����
	*	ʹ��һ��bool���飬��ȫ����Ϊfalse��Ȼ��������飬�����
	*	1��������0��n-1�ķ�Χ�ڣ��򷵻�false��
	*	2��û�з��ʹ����������bool�����λ��Ϊtrue��
	*	3�����ʹ��ˣ��򱣴�����ظ����ֲ�����true��
	*	4����������ˣ����ʾû���ظ���������false��
	*/
public:
	bool duplicate(int numbers[], int length, int* duplication) {
		if (length <= 0 || numbers == NULL)
			return false;
		bool *visited = new bool[length];
		memset(visited, 0, sizeof(visited));
		for (int i = 0; i < length; ++i) {
			if (numbers[i] < 0 || numbers[i] >= length)
				return false;
			if (visited[numbers[i]] == false)
				visited[numbers[i]] = true;
			else {
				duplication[0] = numbers[i];
				delete[]visited;
				return true;
			}
		}
		delete[]visited;
		return false;
	}
};