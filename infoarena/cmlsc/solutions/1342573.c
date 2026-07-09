#include<stdio.h>
#include<stdlib.h>
#define max(a,b) (a > b) ? a : b
#define Nmax 1025

int A[Nmax],B[Nmax],mat[Nmax][Nmax],sol[Nmax];

int main()
{
    int i,j,n,m,nrs=0;
    FILE*fi,*fo;
    fi=fopen("cmlsc.in","r");
    fo=fopen("cmlsc.out","w");
    fscanf(fi,"%d%d",&n,&m);
    for(i=1;i<=n;i++)
        fscanf(fi,"%d",&A[i]);
    for(i=1;i<=m;i++)
        fscanf(fi,"%d",&B[i]);
    for(i=1;i<=n;++i)
        for(j=1;j<=m;++j)
            if(A[i]==B[j])
                mat[i][j]=mat[i-1][j-1] + 1;
            else
                mat[i][j] = max(mat[i-1][j],mat[i][j-1]);
    i=n;
    j=m;
    while(i)
        if(A[i]==B[j])
        {
            sol[++nrs] = A[i];
            i--,j--;
        }
        else if(mat[i-1][j] < mat[i][j-1])
            j--;
        else
            i--;
    fprintf(fo,"%d\n",nrs);
    for(i=nrs; i; --i)
        fprintf(fo,"%d ",sol[i]);
    fclose(fi);
    fclose(fo);
    return 0;
}
