#include "global.h"

class Solution {
	/*Question 29 最小的K个数
	*题目描述
	*	输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4。
	*	时间限制：1秒 空间限制：32768K
	*思路描述
	*	1、最简单的办法：排序取前k位，复杂度O(nlogn)。
	*	2、冒泡排序法：外层循环只循环k次，复杂度O(nk)。
	*	3、堆排序算法：将前k个数入最大堆，然后对后来的每个数都和堆顶的数进行比较。复杂度O(nlogk) *Recommend*
	*	Note:K有可能大于数组长度，大于时返回空数组，等于时返回原数组。
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