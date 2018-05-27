#include "global.h"

class Solution {
	/*Question 4
	*��Ŀ����
	*	����ĳ��������ǰ���������������Ľ�������ؽ����ö�������
	*	���������ǰ���������������Ľ���ж������ظ������֡�
	*	��������ǰ���������{1,2,4,7,3,5,6,8}�������������{4,7,2,1,5,3,8,6}�����ؽ������������ء�
	*	struct TreeNode {
	*		int val;
	*		TreeNode *left;
	*		TreeNode *right;
	*		TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	*	};
	*	ʱ�����ƣ�1�� �ռ����ƣ�32768K
	*˼·����
	*	�ݹ�˼�룬����ǰ������ĵ�һλȷ�����ڵ㣬�ٴ�����������ҵ������������ڸ��ڵ�֮ǰ�������������ڸ��ڵ�֮�������������
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