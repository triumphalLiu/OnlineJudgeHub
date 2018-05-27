#include "global.h"

class Solution {
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
	*	Hint: vector<type> v2(v1.begin(), v1.end())  ==  copy v1 to v2
	*/
	struct TreeNode {
		int val;
		TreeNode *left;
		TreeNode *right;
		TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	};
public:
	TreeNode * reConstructBinaryTree(vector<int> pre, vector<int> vin) {
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