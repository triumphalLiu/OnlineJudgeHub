#include "global.h"

class Solution {
	/*Question 35 �����е������
	*��Ŀ����
	*	�������е��������֣����ǰ��һ�����ִ��ں�������֣����������������һ������ԡ�
	*	����һ������,�����������е�����Ե�����P������P��1000000007ȡģ�Ľ������� �����P%1000000007
	*	��Ŀ��֤�����������û�е���ͬ������
	*	���ݷ�Χ��
	*		����%50������,size<=10^4
	*		����%75������,size<=10^5
	*		����%100������,size<=2*10^5
	*	ʱ�����ƣ�1�� �ռ����ƣ�65536K
	*˼·����
	*	˫��ѭ���϶��ǲ��еģ�ʱ�临�Ӷ�̫�ߡ�
	*	ʹ�ù鲢����Ĳ��˼�롣ʱ�临�Ӷ�O(nlogn)
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