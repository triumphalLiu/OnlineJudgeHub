#include "global.h"

class Solution {
	/*Question 23 二叉搜索树的后序遍历序列
	*题目描述
	*	输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则输出Yes,否则输出No。
	*	假设输入的数组的任意两个数字都互不相同。
	*	时间限制：1秒 空间限制：32768K
	*思路描述
	*	二叉搜索树的特性，左子树的值都小于根节点，右子树的值都大于根节点。
	*	Note: sequence为空的时候返回false。
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