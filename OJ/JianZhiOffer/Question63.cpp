#include "global.h"

class Solution {
	/*Question 63 �������е���λ��
	*��Ŀ����
	*	��εõ�һ���������е���λ����
	*	������������ж�����������ֵ����ô��λ������������ֵ����֮��λ���м����ֵ��
	*	������������ж���ż������ֵ����ô��λ������������ֵ����֮���м���������ƽ��ֵ��
	*	ʱ�����ƣ�1�� �ռ����ƣ�32768K
	*˼·����
	*	ʹ�ÿ��������partition˼�룬ϣ���ҵ�һ���м�㣬ʹ��ߵ�С�ڸ�ֵ���ұߴ��ڸ�ֵ����ô���ֵ/����ֵ֮ƽ��������λ����
	*	Note����Ϊż��ʱ����Ҫ�ҵ��м������м�㣬����mid��ֵҪ����ȡ��������ֻ����ߵ��м����ȷ��
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