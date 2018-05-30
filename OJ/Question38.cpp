#include "global.h"

class Solution {
	/*Question 38 二叉树的深度
	*题目描述
	*	输入一棵二叉树，求该树的深度。从根结点到叶结点依次经过的结点（含根、叶结点）形成树的一条路径，最长路径的长度为树的深度。
	*	时间限制：1秒 空间限制：32768K
	*思路描述
	*	统计层次遍历的层次数，用队列保存接下来要访问的根节点，并设定一个offset值用于保存下一层的节点数，每一次循环增加一个count，当count等于offset时表示某一层已经访问完成。
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
	int TreeDepth(TreeNode* pRoot) {
		if (pRoot == NULL) return 0;
		int maxDepth = 0, cnt = 0, offset = 1;
		queue<TreeNode *> treeQueue;
		treeQueue.push(pRoot);
		while (treeQueue.empty() == false) {
			TreeNode *currentNode = treeQueue.front();
			treeQueue.pop();
			if (currentNode->left != NULL)
				treeQueue.push(currentNode->left);
			if (currentNode->right != NULL)
				treeQueue.push(currentNode->right);
			if (++cnt == offset) {
				maxDepth++;
				offset = treeQueue.size();
				cnt = 0;
			}
		}
		return maxDepth;
	}

	/*Use For Debug*/
	int Debug() {
		TreeNode *fir = new TreeNode(1);
		TreeNode *sec = new TreeNode(2);
		TreeNode *thr = new TreeNode(3);
		TreeNode *fou = new TreeNode(4);
		TreeNode *fiv = new TreeNode(5);
		TreeNode *six = new TreeNode(6);
		TreeNode *sev = new TreeNode(7);
		fir->left = sec; fir->right = fou;
		sec->right = thr;
		fou->left = fiv; 
		fiv->left = six;
		six->left = sev;
		cout << TreeDepth(fir) << endl;
		return 0;
	}
};