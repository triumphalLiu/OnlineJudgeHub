#include "global.h"

class Solution {
	/*Question 51 �����˻�����
	*��Ŀ����
	*	����һ������A[0,1,...,n-1],�빹��һ������B[0,1,...,n-1],����B�е�Ԫ��B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]������ʹ�ó�����
	*	ʱ�����ƣ�1�� �ռ����ƣ�32768K
	*˼·����
	*	������B[i]�����������i�еĳ˻����ɣ��ȼ��������ǵĳ˻����ټ��������ǵĳ˻���
	*   1 A1 A2 ... An-2 An-1 = B0
	*	A0 1 A2 ... An-2 An-1 = B1
	*	A0 A1 1 ... An-2 An-1 = B2
	*   ...     ...       ...
	*   A0 A1 A2 .. 1    An-1 = Bn-2
	*   A0 A1 A2 .. An-2 1    = Bn-1
	*/
public:
	vector<int> multiply(const vector<int>& A) {
		vector<int> B;
		B.push_back(1);
		for (int i = 1; i < A.size(); ++i) {
			B.push_back(1);
			B[i] = B[i - 1] * A[i - 1];
		}
		int base = 1;
		for (int i = A.size() - 2; i >= 0; --i) {
			B[i] *= (base *= A[i + 1]);
		}
		return B;
	}
};