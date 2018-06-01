#include "global.h"

class Solution {
	/*Question 63 数据流中的中位数
	*题目描述
	*	如何得到一个数据流中的中位数？
	*	如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。
	*	如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。
	*	时间限制：1秒 空间限制：32768K
	*思路描述
	*	使用快速排序的partition思想，希望找到一个中间点，使左边的小于该值，右边大于该值，那么这个值/两个值之平均就是中位数。
	*	Note：当为偶数时，需要找到中间两个中间点，所以mid的值要向上取整，否则只有左边的中间点正确。
	*/
public:
	vector<int> numArray;
	void Insert(int num) {
		numArray.push_back(num);
	}

	void partition(int left, int right) {
		if (left >= right) return;
		while (true) {
			int mid = (int)ceil((left + right) / 2.0);
			int pos = left;
			for (int i = left + 1; i <= right; ++i) {
				if (numArray[i] < numArray[left]) {
					pos++;
					int temp = numArray[i];
					numArray[i] = numArray[pos];
					numArray[pos] = temp;
				}
			}
			int temp = numArray[left];
			numArray[left] = numArray[pos];
			numArray[pos] = temp;
			if (pos == mid) 
				return;
			else if (pos > mid)
				right = pos - 1;
			else if (pos < mid)
				left = pos + 1;
		}
	}

	double GetMedian() {
		if (numArray.size() == 0) return 0;
		partition(0, numArray.size() - 1);
		int mid = numArray.size() / 2;
		return (numArray.size() & 1) ? (numArray[mid]) : (numArray[mid] + numArray[mid - 1]) / 2.0;
	}

	/*Use For Debug*/
	int Debug() {
		Insert(5);
		cout << GetMedian() << endl; //5
		Insert(6);
		cout << GetMedian() << endl; //5.5
		Insert(4);
		cout << GetMedian() << endl; //5
		Insert(2);
		cout << GetMedian() << endl; //4.5
		Insert(8);
		cout << GetMedian() << endl; //5
		Insert(7);
		cout << GetMedian() << endl; //5.5
		Insert(1);
		cout << GetMedian() << endl; //5
		Insert(3);
		cout << GetMedian() << endl; //4.5
		return 0;
	}
};