#include "global.h"

class Solution {
	/*Question 24 �������к�Ϊĳһֵ��·��
	*��Ŀ����
	*	����һ�Ŷ�������һ����������ӡ���������н��ֵ�ĺ�Ϊ��������������·����
	*	·������Ϊ�����ĸ���㿪ʼ����һֱ��Ҷ����������Ľ���γ�һ��·����
	*	ʱ�����ƣ�1�� �ռ����ƣ�32768K
	*˼·����
	*	���ȱ��������·�����еĵ㣬�����浽ջ�У�����·���и��ڵ��value���浽����sum�У��������µĲ����У���ջsum������ջsum�ӣ�
	*	�����ǰ����Ҷ�ӽڵ㣬��ô�Ƚ�sum��expectNumber�������ȣ���ѵ�ǰջ��·�����浽����У�
	*	Ȼ��Ҫ���л��˲���������ǰ�Ľڵ㱣��ΪlastNode��Ȼ��currentRoot�˻ص���һ�ڵ㣬�Ƚ�currentRoot���Ҳ�ڵ㣬�����lastNode������Ҳ�Ϊ�գ���ô���ҽڵ���ջ��
	*	���������һ����ֱ���ҵ�û�б��������ҽڵ㣬����ջΪ���˳���
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