#include "global.h"

class Solution {
	/*Question 58 �ԳƵĶ�����
	*��Ŀ����
	*	��ʵ��һ�������������ж�һ�Ŷ������ǲ��ǶԳƵġ�ע�⣬���һ��������ͬ�˶������ľ�����ͬ���ģ�������Ϊ�ԳƵġ�
	*	ʱ�����ƣ�1�� �ռ����ƣ�32768K
	*˼·����
	*	���ò�α�������¼ÿһ����ڵ�ĵ�ַ������NULL����ÿ����һ�㣬���Ƿ�ͷ�ת�Ľ��һ�£�NULL����ƥ��NULL���ǿ�ָ���ֵ����ƥ��ǿ�ָ���ֵ�������򷵻�false��
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