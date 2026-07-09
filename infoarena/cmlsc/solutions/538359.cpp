#include<stdio.h>
#define NMAX 1025
FILE *in,*out;

inline int maxim(int a,int b)
{
    if(a>b)
        return a;
    return b;
}

int N,M,A[NMAX],B[NMAX],D[6][4],i,j,cont,sir[NMAX];
int main()
{
    in=fopen("cmlsc.in","rt");
    out=fopen("cmlsc.out","wt");
    fscanf(in,"%d %d",&M,&N);
    for(i=1;i<=M;i++)
        fscanf(in,"%d",&A[i]);
    for(i=1;i<=N;i++)
        fscanf(in,"%d",&B[i]);
    for(i=1;i<=M;i++)
        for(j=1;j<=N;j++)
        {
            if(A[i]==B[j])
                D[i][j]=1+D[i-1][j-1];
            else
                D[i][j]=maxim(D[i-1][j],D[i][j-1]);
        }
    for(i=M,j=N; i; )
    {
        if(A[i]==B[j])
        {
            sir[++cont]=A[i];
            i--;
            j--;
        }
        else
            if(D[i-1][j]<D[i][j-1])
                j--;
            else
                i--;
    }

    fprintf(out,"%d\n",cont);
    for(i=cont;i;i--)
    {
        fprintf(out,"%d ",sir[i]);
    }

    return 0;
}
