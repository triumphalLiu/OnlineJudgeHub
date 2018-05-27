#include "global.h"

class Solution {
public:
	/*Question 1
	*题目描述
	*	在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
	*   请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
	*	时间限制：1秒 空间限制：32768K
	*思路描述
	*	从右上角开始检查，如果小于目标，就放弃这一行；如果大于目标，就放弃这一列；然后对缩小后的矩阵进行遍历。
	*/
	bool Find(int target, vector<vector<int> > array) {
		int col = array[0].size();
		for (int i = 0; i < array.size(); ++i) {
			for (int j = col - 1; j >= 0; --j) {
				if (array[i][j] == target)
					return true;
				else if (j == col - 1 && array[i][j] < target)
					break;
				else if (j == col - 1 && array[i][j] > target)
					j = (col -= 1);
			}
		}
		return false;
	}

	/*Question 2
	*题目描述
	*	请实现一个函数，将一个字符串中的空格替换成“%20”。
	*	例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
	*	时间限制：1秒 空间限制：32768K
	*思路描述
	*	统计空格的数量，再从后往前进行替换。
	*/
	void replaceSpace(char *str, int length) {
		int spaceCount = 0;
		for (int i = 0; i < length; ++i)
			if (str[i] == ' ')
				spaceCount++;
		int newLen = spaceCount * 2 + length;
		str[newLen] = '\0';
		for (int i = length - 1; i >= 0; --i) {
			if (str[i] != ' ')
				str[i + spaceCount * 2] = str[i];
			else if (str[i] == ' ') {
				str[i + spaceCount * 2] = '0';
				str[i + spaceCount * 2 - 1] = '2';
				str[i + spaceCount * 2 - 2] = '%';
				spaceCount--;
			}
		}
	}

	/*Question 3
	*题目描述
	*	输入一个链表，从尾到头打印链表每个节点的值。
	*   struct ListNode {
	*         int val;
	*         struct ListNode *next;
	*         ListNode(int x) :
	*               val(x), next(NULL) {
	*         }
	*   };
	*	时间限制：1秒 空间限制：32768K
	*思路描述
	*	使用栈的数据结构，按顺序遍历链表并压栈，然后一个一个出栈放入vector中。
	*/
	vector<int> printListFromTailToHead(ListNode* head) {
		vector<int> result;
		stack<int> middle;
		ListNode *pt = head;
		while (pt != NULL) {
			middle.push(pt->val);
			pt = pt->next;
		}
		while (middle.empty() == false) {
			result.push_back(middle.top());
			middle.pop();
		}
		return result;
	}

	/*Question 4
	*题目描述
	*	输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
	*	假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
	*	例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。
	*	struct TreeNode {
	*		int val;
	*		TreeNode *left;
	*		TreeNode *right;
	*		TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	*	};
	*	时间限制：1秒 空间限制：32768K
	*思路描述
	*	递归思想，根据前序遍历的第一位确定根节点，再从中序遍历中找到左右子树：在根节点之前的是左子树，在根节点之后的是右子树。
	*/
	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
		if (pre.size() == 0 || vin.size() == 0)
			return NULL;
		TreeNode *root = new TreeNode(pre[0]);
		cout << root->val << endl;
		for (int i = 0; i < vin.size(); ++i) {
			if (vin[i] == root->val) {
				vector<int> vinleft(vin.begin(), vin.begin() + i);
				vector<int> vinright(vin.begin() + i + 1, vin.end());
				vector<int> preleft(pre.begin() + 1, pre.begin() + i + 1);
				vector<int> preright(pre.begin() + i + 1, pre.end());
				root->left = reConstructBinaryTree(preleft, vinleft);
				root->right = reConstructBinaryTree(preright, vinright);
				return root;
			}
		}
		return NULL;
	}
};

int main() {
	Solution solution;
	vector<int> pre = { 1,2,4,7,3,5,6,8 };
	vector<int> vin = { 4,7,2,1,5,3,8,6 };
	solution.reConstructBinaryTree(pre, vin);
	return 0;
}