#include "global.h"

class Solution {
	/*Question 23 �����������ĺ����������
	*��Ŀ����
	*	����һ���������飬�жϸ������ǲ���ĳ�����������ĺ�������Ľ��������������Yes,�������No��
	*	�������������������������ֶ�������ͬ��
	*	ʱ�����ƣ�1�� �ռ����ƣ�32768K
	*˼·����
	*	���������������ԣ���������ֵ��С�ڸ��ڵ㣬��������ֵ�����ڸ��ڵ㡣
	*	Note: sequenceΪ�յ�ʱ�򷵻�false��
	*/
public:
	bool VerifySquenceOfBST(vector<int> sequence) {
		if (sequence.size() == 0)
			return false;
		if (sequence.size() == 1)
			return true;
		int rootValue = sequence[sequence.size() - 1];
		int index = sequence.size() - 1;
		for (int i = 0; i < sequence.size() - 1; ++i) {
			if (sequence[i] > rootValue)
				index = i;
			if (i > index && sequence[i] < rootValue)
				return false;
		}
		vector<int> leftTree(sequence.begin(), sequence.begin() + index);
		vector<int> rightTree(sequence.begin() + index, sequence.end() - 1);
		if (leftTree.empty())
			return VerifySquenceOfBST(rightTree);
		else if(rightTree.empty())
			return VerifySquenceOfBST(leftTree);
		else
			return VerifySquenceOfBST(leftTree) && VerifySquenceOfBST(rightTree);
	}

	/*Use For Debug*/
	int Debug() {
		Solution s;
		vector<int> arr = { 4,8,6,12,16,14,10 };
		cout << s.VerifySquenceOfBST(arr);
		return 0;
	}
};