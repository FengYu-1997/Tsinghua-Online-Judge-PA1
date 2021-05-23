#pragma warning(disable:4996) //在visual stdio环境下忽略scanf unsafe错误
#include<iostream>
#include<cstdio>
using namespace std;
typedef int Rank;

void merge(int* Arr, Rank lo, Rank mi, Rank hi) {
	int* A = Arr + lo;

	int lb = mi - lo; int* B = new int[lb];
	for (int i = 0; i < lb; i++) B[i] = A[i];

	int lc = hi - mi; int* C = Arr + mi;
	for (int i = 0, j = 0, k = 0; j < lb;) {  //C本身就在A中，B中元素就位后，C中元素自动就位
		if (k < lc && C[k] < B[j]) A[i++] = C[k++];
		else A[i++] = B[j++];
		//if ( !(k < lc) || B[j] <= C[k] ) A[i++] = B[j++];
	}
	/*for (int i = 0, j = 0, k = 0; (j < lb) || (k < lc); ) {
		if ( (j < lb) && (!(k < lc) || (B[j] <= C[k]) ) ) A[i++] = B[j++];
		if ( (k < lc) && (!(j < lb) || (C[k] < B[j]) )  ) A[i++] = C[k++];
	}*/
	delete[] B;
}
void mergeSort(int* A, Rank lo, Rank hi) { 
	if (hi - lo < 2) return;
	Rank mi = (hi + lo) >> 1; //移位比除法更快
	mergeSort(A, lo, mi);
	mergeSort(A, mi, hi);
	merge(A, lo, mi, hi);
}

Rank binSearch(int A[], int const& e, Rank lo, Rank hi) {
	Rank mi;
	while (lo < hi) {
		mi = (lo + hi) >> 1;
		(e < A[mi]) ? hi = mi : lo = mi + 1;
	}
	return --lo; //返回不大于e的最后一个元素的秩
}

int main() {
	int n, m;
	cin >> n >> m;

	int* A = new int[n];
	int* left = new int[m];
	int* right = new int[m];

	for (int i = 0; i < n; i++) scanf("%d", &A[i]);  //scanf 略快于 cin
	for (int i = 0; i < m; i++) scanf("%d %d", &left[i], &right[i]);

	mergeSort(A, 0, n);
	
	int count;
	for (int round = 0; round < m; round++) {
		Rank rl = binSearch(A, left[round], 0, n);
		Rank rr = binSearch(A, right[round], rl, n);

		count = rr - rl + int(rl >= 0 && left[round] == A[rl]); //若左边界在A中，count加一
		printf("%d\n", count); //printf 比 cout 快得多
	}

}

