#include<stdio.h>
#include<stdlib.h>

void citire(int *a,int n,FILE *f)
{
    int i;
    for(i=0; i<n; i++)
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

int LCS(int *a,int*b,int m,int n,int *arr)
{
    static int k=0;
    if(m==0 || n==0)
        return 0;
    else if(a[m-1]==b[n-1])
    {
        arr[k++]=a[m-1];
        return 1+LCS(a,b,m-1,n-1,arr);
    }
    else
    {
        return max( LCS(a,b,m-1,n,arr), LCS(a,b,m,n-1,arr) );
    }
}

int main()
{
    FILE *f=fopen("cmlsc.in","r");
    FILE *g=fopen("cmlsc.out","w");
    int M,N;
    fscanf(f,"%d%d",&M,&N);
    int A[M];
    int B[N];
    citire(A,M,f);
    citire(B,N,f);
    int size=max(M,N);
    int arr[size];
    int len=LCS(A,B,M,N,arr);
    fprintf(g,"%d\n",len);
    for(int i=len-1;i>=0;i--)
        fprintf(g,"%d ",arr[i]);
}
