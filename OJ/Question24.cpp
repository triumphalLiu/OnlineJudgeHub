#include "global.h"

class Solution {
	/*Question 24 二叉树中和为某一值的路径
	*题目描述
	*	输入一颗二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
	*	路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
	*	时间限制：1秒 空间限制：32768K
	*思路描述
	*	首先遍历最左侧路径所有的点，并保存到栈中，并把路径中各节点的value保存到变量sum中；（在以下的操作中，出栈sum减，入栈sum加）
	*	如果当前到了叶子节点，那么比较sum和expectNumber，如果相等，则把当前栈的路径保存到结果中；
	*	然后要进行回退操作：将当前的节点保存为lastNode，然后将currentRoot退回到上一节点，比较currentRoot的右侧节点，如果和lastNode不想等且不为空，那么将右节点入栈；
	*	否则继续上一步，直到找到没有遍历过的右节点，或者栈为空退出。
	*/
	struct TreeNode {
		int val;
		struct TreeNode *left;
		struct TreeNode *right;
		TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
		}
	};
public:
	vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
		vector<vector<int>> result;
		if (root == NULL) return result;
		stack<TreeNode *> treeStack;
		treeStack.push(root);
		int sum = root->val;
		while (treeStack.empty() == false) {
			TreeNode *currentRoot = treeStack.top();
			if (currentRoot->left == NULL && currentRoot->right == NULL) {
				if (sum == expectNumber) {
					stack<TreeNode *> backupStack;
					while (treeStack.empty() == false) {
						backupStack.push(treeStack.top());
						treeStack.pop();
					}
					vector<int> tempVector;
					while (backupStack.empty() == false) {
						tempVector.push_back(backupStack.top()->val);
						treeStack.push(backupStack.top());
						backupStack.pop();
					}
					result.push_back(tempVector);
				}
				while (1) {
					TreeNode *lastNode = currentRoot;
					treeStack.pop();
					sum -= currentRoot->val;
					if (treeStack.empty())
						return result;
					else
						currentRoot = treeStack.top();
					if (currentRoot->right != NULL && lastNode != currentRoot->right)
						break;
				}
				treeStack.push(currentRoot->right);
				sum += currentRoot->right->val;
			}
			else if (currentRoot->left != NULL) {
				treeStack.push(currentRoot->left);
				sum += currentRoot->left->val;
			}
			else {
				treeStack.push(currentRoot->right);
				sum += currentRoot->right->val;
			}
		}
		return result;
	}

	/*Use For Debug*/
	void Display(vector<vector<int>> rtn) {
		for (int i = 0; i < rtn.size(); ++i) {
			for (int j = 0; j < rtn[i].size(); ++j)
				cout << rtn[i][j] << " ";
			cout << endl;
		}
	}
	int Debug() {
		Solution s;
		TreeNode *root = new TreeNode(10);
		root->left = new TreeNode(5);
		root->right = new TreeNode(12);
		//root->left->right = new TreeNode(7);
		root->left->left = new TreeNode(4);
		vector<vector<int>> rtn = s.FindPath(root, 22);
		Display(rtn);
		return 0;
	}
};