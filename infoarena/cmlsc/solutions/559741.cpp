#include<cstring>
#include<iostream>
#include<cstdio>
short D[1030][1030],a[1030],b[1030];
int LCS(int i,int j)
{
    if(i==0 || j==0)
    {
        return 0;
    }
    if(D[i][j]==-1)
    {
        if(a[i]==b[j])
            D[i][j]=LCS(i-1,j-1)+1;
        else
            D[i][j]=std::max(LCS(i-1,j),LCS(i,j-1));
    }
    return D[i][j];
}
int main()
{
    FILE* fin=fopen("cmlsc.in","r"),
            *fout=fopen("cmlsc.out","w");
    int n,m,i,j;
    fscanf(fin,"%d %d",&n,&m);
    for(i=1;i<=n;++i)
        fscanf(fin,"%d",&a[i]);
    for(j=1;j<=m;++j)
        fscanf(fin,"%d",&b[j]);

    memset(D,0xff,sizeof(D));
    D[n][m]=LCS(n,m);

    fprintf(fout,"%d\n",D[n][m]);

    short sir[1030];
    int len=0;
    for(i=n,j=m;i;)
    {
        if(a[i]==b[j])
        {
            sir[len++]=a[i];
            i--,j--;
        }
        else if(D[i-1][j]<D[i][j-1])
            j--;
        else
            i--;
    }

    for(i=len-1;i>=0;--i)
        fprintf(fout,"%d ",sir[i]);
    putc('\n',fout);
    return 0;
}
