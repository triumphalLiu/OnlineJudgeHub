#include "global.h"

class Solution {
	/*Question 38 �����������
	*��Ŀ����
	*	����һ�ö����������������ȡ��Ӹ���㵽Ҷ������ξ����Ľ�㣨������Ҷ��㣩�γ�����һ��·�����·���ĳ���Ϊ������ȡ�
	*	ʱ�����ƣ�1�� �ռ����ƣ�32768K
	*˼·����
	*	ͳ�Ʋ�α����Ĳ�������ö��б��������Ҫ���ʵĸ��ڵ㣬���趨һ��offsetֵ���ڱ�����һ��Ľڵ�����ÿһ��ѭ������һ��count����count����offsetʱ��ʾĳһ���Ѿ�������ɡ�
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