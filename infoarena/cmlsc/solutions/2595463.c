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

int LCS(int* a,int* b,int*c,int m,int n)
{
    int k=1;
    if( m==0 || n==0)
        return 0;

    else if(a[m-1]==b[n-1])
        return 1 + LCS(a,b,c,m-1,n-1);
    else
        return max(LCS(a,b,c,m-1,n), LCS(a,b,c,m,n-1));
}

int main()
{
    FILE* f=fopen("cmlsc.in","r");
    FILE* g=fopen("cmlsc.out","w");
    int size1,size2;
    fscanf(f,"%d%d",&size1,&size2);
    int a[size1];
    int b[size2];
    int c[100];
    citire(a,size1,f);
    citire(b,size2,f);
    fprintf(g,"%d",LCS(a,b,c,size1,size2));
    return 0;
}
