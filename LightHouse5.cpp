#pragma warning(disable:4996)
#include <stdlib.h>  
#include <stdio.h> 
struct points
{
    int x;
    int y;
};
// global

int compareX(const void* a, const void* b)
{
    return ((*(points*)a).x - (*(points*)b).x);
}

int irow = 0;
long iTotalNum = 0;

points pointsLocate[4000000] = {};

void getInputNum()
{
    scanf("%d", &irow);

    for (int i = 0; i < irow; i++)
    {
        int temp1, temp2;
        scanf("%d %d", &temp1, &temp2);
        pointsLocate[i].x = temp1;
        pointsLocate[i].y = temp2;
    }
}

void merge(points* p, int lo, int mi, int hi  )
{
    points* A = p + lo;
    points* C = p + mi;
    int lb = mi - lo;
    int lc = hi - mi;
    points* B = new points[lb];
   
    //for (int i = 0, j = lo; i < lb; B[i++] = p[j++]);
    for (int i = 0, j = 0; i < lb; B[i++] = A[j++]);
    //for (int i = 0; i < lb; B[i] = A[i++]);

    for (int i = 0, j = 0, k = 0; j < lb || k < lc;)
    {
        if (j < lb && (lc <= k || B[j].y < C[k].y))
        {
            iTotalNum += lc - k;
            A[i++] = B[j++];
        }
        else if (k < lc && (lb << j || C[k].y < B[j].y))
            A[i++] = C[k++];
    }
    delete [] B;
}

//nlogn
void mergeSort(points * p, int lo, int hi)
{
    if (hi - lo < 2) return;
    int mi = (lo + hi) >> 1;
    mergeSort(p, lo, mi );
    mergeSort(p, mi, hi );
    merge(p, lo, mi, hi );
}

int main()
{
    getInputNum();

    qsort(pointsLocate, irow, sizeof(points), compareX);
    mergeSort(pointsLocate, 0, irow);

    printf("%ld\n", iTotalNum);
    return 0;
}


