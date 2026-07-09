#include<cstdio>
int A[1024],B[1024],L[1025][1025],n,m,MAX;
FILE*q=fopen("cmlsc.out","w");

void citire()
{
    FILE*f=fopen("cmlsc.in","r");
    fscanf(f,"%d%d",&n,&m);
    for(int i=0;i<n;++i) fscanf(f,"%d",&A[i]);
    for(int i=0;i<m;++i) fscanf(f,"%d",&B[i]);
    fclose(f);
}

int cmlsc()
{
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
        {
            if(A[i-1]==B[j-1])
                L[i][j]=L[i-1][j-1]+1;
            else
                if(L[i-1][j]>L[i][j-1])
                    L[i][j]=L[i-1][j];
                else L[i][j]=L[i][j-1];
        }
    return L[n][m];
}

void solutie(int x,int y)
{
    if(x<1||y<1) return;

    if(A[x-1]==B[y-1])
    {
        solutie(x-1,y-1);
        fprintf(q,"%d ",A[x-1]);
    }
    else
        if(L[x-1][y]>L[x][y-1])
            solutie(x-1,y);
        else solutie(x,y-1);
}

int main()
{
    citire();
    MAX=cmlsc();
    fprintf(q,"%d\n",MAX);
    solutie(n,m);
    fclose(q);
    return 0;
}
