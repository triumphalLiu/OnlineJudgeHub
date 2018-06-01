#include "global.h"

class Solution {
	/*Question 58 对称的二叉树
	*题目描述
	*	请实现一个函数，用来判断一颗二叉树是不是对称的。注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。
	*	时间限制：1秒 空间限制：32768K
	*思路描述
	*	采用层次遍历，记录每一层各节点的地址（包括NULL），每遍历一层，看是否和反转的结果一致（NULL必须匹配NULL，非空指针的值必须匹配非空指针的值），否则返回false。
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
	bool isSymmetrical(TreeNode* pRoot) {
		if (pRoot == NULL) return true;
		int cnt = 0, offset = 1;
		queue<TreeNode *> treeQueue;
		vector<TreeNode *> levelSequence;
		treeQueue.push(pRoot);
		while (treeQueue.empty() == false) {
			TreeNode *currentNode = treeQueue.front();
			levelSequence.push_back(currentNode);
			treeQueue.pop();
			if (currentNode != NULL) {
				treeQueue.push(currentNode->left);
				treeQueue.push(currentNode->right);
			}
			if (++cnt == offset) {
				offset = treeQueue.size();
				cnt = 0;
				for (int i = 0; i < levelSequence.size() / 2; ++i) {
					if (levelSequence[i] == NULL && levelSequence[levelSequence.size() - 1 - i] != NULL)
						return false;
					if (levelSequence[levelSequence.size() - 1 - i] == NULL && levelSequence[i] != NULL)
						return false;
					if (levelSequence[i]->val != levelSequence[levelSequence.size() - 1 - i]->val)
						return false;
				}
				levelSequence = {};
			}
		}
		return true;
	}

	/*Use For Debug*/
	int Debug() {
		TreeNode *fir = new TreeNode(5);
		TreeNode *sec = new TreeNode(5);
		TreeNode *thr = new TreeNode(5);
		TreeNode *fou = new TreeNode(5);
		TreeNode *fiv = new TreeNode(5);
		fir->left = sec; fir->right = thr;
		sec->right = fou;
		thr->right = fiv;
		cout << isSymmetrical(fir) << endl;
		return 0;
	}
};