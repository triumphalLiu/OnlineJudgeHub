#include "global.h"

class Solution {
	/*Question 35 数组中的逆序对
	*题目描述
	*	在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。
	*	输入一个数组,求出这个数组中的逆序对的总数P。并将P对1000000007取模的结果输出。 即输出P%1000000007
	*	题目保证输入的数组中没有的相同的数字
	*	数据范围：
	*		对于%50的数据,size<=10^4
	*		对于%75的数据,size<=10^5
	*		对于%100的数据,size<=2*10^5
	*	时间限制：1秒 空间限制：65536K
	*思路描述
	*	双重循环肯定是不行的，时间复杂度太高。
	*	使用归并排序的拆分思想。时间复杂度O(nlogn)
	*/
public:
	long long count = 0;
	int InversePairs(vector<int> data) {
		mergeSort(data, 0, data.size() - 1);
		return count % 1000000007;
	}

	void mergeOper(vector<int> &arr, int start, int mid, int end) {
		int *temp = new int[end - start + 1];
		int i = start, j = mid + 1, k = 0;
		while (i <= mid && j <= end)
		{
			if (arr[i] > arr[j]) {
				temp[k++] = arr[j++];
				count += ((mid - i + 1) % 1000000007);
			}
			else
				temp[k++] = arr[i++];
		}
		while (i <= mid)
			temp[k++] = arr[i++];
		while (j <= end)
			temp[k++] = arr[j++];
		for (int s = 0; s < end - start + 1; ++s)
			arr[start + s] = temp[s];
	}

	void mergeSort(vector<int> &arr, int start, int end) {
		if (start < end)
		{
			int mid = (start + end) >> 1;
			mergeSort(arr, start, mid);
			mergeSort(arr, mid + 1, end);
			mergeOper(arr, start, mid, end);
		}
	}

	/*Use For Debug*/
	int Debug() {
		vector<int> arr = { 1,2,3,4,5,6,7,0 };
		cout << InversePairs(arr) << endl;
		return 0;
	}
};