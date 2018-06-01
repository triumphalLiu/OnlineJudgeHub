#include "global.h"

class Solution {
	/*Question 59 ��֮����˳���ӡ������
	*��Ŀ����
	*	��ʵ��һ����������֮���δ�ӡ������������һ�а��մ����ҵ�˳���ӡ���ڶ��㰴�մ��������˳���ӡ�������а��մ����ҵ�˳���ӡ���������Դ����ơ�
	*	ʱ�����ƣ�1�� �ռ����ƣ�32768K
	*˼·����
	*	��α����ı�ʽ�����԰Ѳ�α���ʹ�õĶ��нṹ�ĳ�����ṹ���ȶԵ�һ�н��д�ӡ��
	*	Ȼ��ÿ�б�������ʱ����һ�м��������Ľڵ��ֵ�����������ǰ�������дӺ���ǰ��ż���д�ǰ����
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