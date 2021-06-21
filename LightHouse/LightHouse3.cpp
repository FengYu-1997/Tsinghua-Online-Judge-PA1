#include<iostream>
using namespace std;
typedef int	Rank;

struct Point
{
	int x;
	int y;
};

long sum = 0; //用作全局变量不能使用count，与std::count冲突

int compareX(const void* a, const void* b)
{
	return ((*(Point*)a).x - (*(Point*)b).x);
}

void ordBetween(int* p, Rank lo, Rank mi, Rank hi) {
	int* A = p + lo;

	int lb = mi - lo; int* B = new int[lb];
	for (int i = 0, j = 0; i < lb; B[i++] = A[j++]); 
	//for (int i = 0; i < lb; B[i] = A[i++]);//书上的单变量i形式在oj时有一大堆 Runtime Error，我也不知道为啥

	int lc = hi - mi; int* C = p + mi;
	for (int i = 0, j = 0, k = 0; j < lb; ) {
		if ((k < lc) && (C[k] < B[j])) A[i++] = C[k++];
		if (!(k < lc) || (B[j] <= C[k])) {
			A[i++] = B[j++]; // j++ 使 j<lb 不一定成立，若先判断B[j]可能导致第二个if下标越界
			sum += lc - k;
		}
	}
	
	delete[] B;
}

void ordInside(int* p, Rank lo, Rank hi) {
	if (hi - lo < 2) return;
	Rank mi = (lo + hi) >> 1;
	ordInside(p, lo, mi);
	ordInside(p, mi, hi);
	ordBetween(p, lo, mi, hi);
}

int main() {
	int n;
	//cin >> n;
	scanf("%d", &n);

	Point* p = new Point[n];
	for (int i = 0; i < n; i++) {
		//cin >> p[i].x >> p[i].y;
		scanf("%d %d", &p[i].x, &p[i].y);//scanf 更快
	}
	qsort(p, n, sizeof(Point), compareX);

	int* y = new int[n];
	for (int i = 0; i < n; i++) y[i] = p[i].y;

	ordInside(y, 0, n);
	cout << sum;
}