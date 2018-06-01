#include "global.h"

class Solution {
	/*Question 59 按之字形顺序打印二叉树
	*题目描述
	*	请实现一个函数按照之字形打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右至左的顺序打印，第三行按照从左到右的顺序打印，其他行以此类推。
	*	时间限制：1秒 空间限制：32768K
	*思路描述
	*	层次遍历的变式，可以把层次遍历使用的队列结构改成数组结构，先对第一行进行打印；
	*	然后每行遍历结束时对下一行即将遍历的节点的值进行输出：当前是奇数行从后往前，偶数行从前往后。
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
	vector<vector<int> > Print(TreeNode* pRoot) {
		if (pRoot == NULL) return {};
		vector<vector<int> > result;
		vector<int> currRow;
		vector<TreeNode *> treeQueue;
		/*Save First Line*/
		treeQueue.push_back(pRoot);
		currRow.push_back(pRoot->val);
		result.push_back(currRow);
		currRow = {};
		int depth = 1, offset = 1, count = 0;
		/*Save Other Line*/
		while (treeQueue.empty() == false) {
			TreeNode *currRoot = treeQueue[0];
			treeQueue.erase(treeQueue.begin());
			if (currRoot->left != NULL)
				treeQueue.push_back(currRoot->left);
			if (currRoot->right != NULL)
				treeQueue.push_back(currRoot->right);
			if (++count == offset) {
				if (treeQueue.empty())
					break;
				offset = treeQueue.size();
				count = 0;
				if (depth & 1) {
					for (int i = treeQueue.size() - 1; i >= 0; --i)
						currRow.push_back(treeQueue[i]->val);
				}
				else {
					for (int i = 0; i < treeQueue.size(); ++i)
						currRow.push_back(treeQueue[i]->val);
				}
				result.push_back(currRow);
				currRow = {};
				++depth;
			}
		}
		return result;
	}

	/*Use For Debug*/
	int Debug() {
		TreeNode *fir = new TreeNode(8);
		TreeNode *sec = new TreeNode(6);
		TreeNode *thr = new TreeNode(10);
		TreeNode *fou = new TreeNode(5);
		TreeNode *fiv = new TreeNode(7);
		TreeNode *six = new TreeNode(9);
		TreeNode *sev = new TreeNode(11);
		fir->left = sec; fir->right = thr;
		sec->left = fou; sec->right = fiv;
		thr->left = six; thr->right = sev;
		vector<vector<int> > result = Print(fir);
		for (int i = 0; i < result.size(); ++i) {
			for (int j = 0; j < result[i].size(); ++j) {
				cout << result[i][j] << " ";
			}
			cout << endl;
		}
		return 0;
	}
};

int main() {
	Solution s;
	return s.Debug();
}