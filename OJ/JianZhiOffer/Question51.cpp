#include "global.h"

class Solution {
	/*Question 51 构建乘积数组
	*题目描述
	*	给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。不能使用除法。
	*	时间限制：1秒 空间限制：32768K
	*思路描述
	*	看作是B[i]是下述矩阵第i行的乘积即可，先计算下三角的乘积，再计算上三角的乘积。
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