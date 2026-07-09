#include <stdio.h>
#include <stdlib.h>

void citire(int* a, int n,FILE* f)
{
    for(int i=0; i<n; i++)
    {
        fscanf(f,"%d",&a[i]);
    }
}

int max(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;
}
int LCS(int* a,int* b,int m,int n, int *arr, int k)
{
    if( m==0 || n==0)
        return 0;
    else if(a[m-1]==b[n-1])
    {
        arr[k++] = a[m-1];
        return 1 + LCS(a,b,m-1,n-1, arr, k);
    }
    else
        return max(LCS(a,b,m-1,n, arr, k), LCS(a,b,m,n-1, arr, k));
}

int main()
{
    FILE* f=fopen("cmlsc.in","r");
    FILE* g=fopen("cmlsc.out","w");
    int size1,size2;
    fscanf(f,"%d%d",&size1,&size2);
    int a[size1];
    int b[size2];
    citire(a,size1,f);
    citire(b,size2,f);
    int size = max(size1, size2);
    int arr[size];
    int lng = LCS(a,b,size1,size2, arr, 0);
    fprintf(g,"%d\n", lng);
    for (int i = lng-1; i >=0 ; i--)
        fprintf(g, "%d ", arr[i]);

    return 0;
}
