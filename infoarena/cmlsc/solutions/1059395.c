#include<stdio.h>
int a[1024],b[1024];
int cmlsc[1024][1024];
int ans[1024],length,nr;
inline int maxof2(int a,int b)
{
    if(a>b)
        return a;
    return b;
}
FILE *fout;
int backtrack(int i,int j)
{
    if(i==0||j==0)
        return 0;
    else
        if(a[i]==b[j])
        {
            ans[nr-length-1]=a[i];
            length++;
            return backtrack(i-1,j-1);
        }
        else
            if(cmlsc[i][j-1]>cmlsc[i-1][j])
                return backtrack(i,j-1);
            else
                return backtrack(i-1,j);
}
int main()
{
    FILE *fin;
    fin=fopen("cmlsc.in","r");
    fout=fopen("cmlsc.out","w");
    int n,m;
    fscanf(fin,"%d%d",&n,&m);
    int i;
    for(i=1;i<=n;i++)
        fscanf(fin,"%d",&a[i]);
    for(i=1;i<=m;i++)
        fscanf(fin,"%d",&b[i]);
    int j;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(a[i]==b[j])
                cmlsc[i][j]=1+cmlsc[i-1][j-1];
            else
                cmlsc[i][j]=maxof2(cmlsc[i-1][j],cmlsc[i][j-1]);
    fprintf(fout,"%d\n",cmlsc[n][m]);
    nr=cmlsc[n][m];
    backtrack(n,m);
    for(i=0;i<nr;i++)
        fprintf(fout,"%d ",ans[i]);
    return 0;
}
