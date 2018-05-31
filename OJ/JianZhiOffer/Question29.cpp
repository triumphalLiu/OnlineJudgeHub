#include "global.h"

class Solution {
	/*Question 29 ��С��K����
	*��Ŀ����
	*	����n���������ҳ�������С��K��������������4,5,1,6,2,7,3,8��8�����֣�����С��4��������1,2,3,4��
	*	ʱ�����ƣ�1�� �ռ����ƣ�32768K
	*˼·����
	*	1����򵥵İ취������ȡǰkλ�����Ӷ�O(nlogn)��
	*	2��ð�����򷨣����ѭ��ֻѭ��k�Σ����Ӷ�O(nk)��
	*	3���������㷨����ǰk���������ѣ�Ȼ��Ժ�����ÿ�������ͶѶ��������бȽϡ����Ӷ�O(nlogk) *Recommend*
	*	Note:K�п��ܴ������鳤�ȣ�����ʱ���ؿ����飬����ʱ����ԭ���顣
	*/
public:
	/*Solution 1 - 3ms 480K*/
	vector<int> GetLeastNumbers_Solution_1(vector<int> input, int k) {
		sort(input.begin(), input.end());
		if (k == input.size()) return input;
		if (k > input.size()) { vector<int> result; return result; }
		vector<int> result(input.begin(), input.begin() + k);
		return result;
	}
	
	/*Solution 2 - 5ms 388K*/
	vector<int> GetLeastNumbers_Solution_2(vector<int> input, int k) {
		vector<int> result;
		if (k > input.size()) return result;
		for (int i = 0; i < k; ++i) {
			for (int j = i + 1; j < input.size(); ++j) {
				if (input[j] < input[i]) {
					int temp = input[j];
					input[j] = input[i];
					input[i] = temp;
				}
			}
			result.push_back(input[i]);
		}
		return result;
	}

	/*Solution 3 - 3ms 480K*/
	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
		if (k > input.size() || k <= 0) return vector<int>();
		vector<int> result(input.begin(), input.begin() + k);
		make_heap(result.begin(), result.end());
		for (int i = k; i < input.size(); ++i) {
			if (input[i] < result[0]) {
				result[0] = input[i];
				make_heap(result.begin(), result.end());
			}
		}
		sort_heap(result.begin(), result.end());
		return result;
	}

	/*Use For Debug*/
	void Display(vector<int> result) {
		for (int i = 0; i < result.size(); ++i)
			cout << result[i] << " ";
		cout << endl;
	}

	int Debug() {
		vector<int> arr = { 3,4,2,6,8,1,5,7,9 };
		vector<int> result = GetLeastNumbers_Solution(arr, 8);
		Display(result);
		return 0;
	}
};