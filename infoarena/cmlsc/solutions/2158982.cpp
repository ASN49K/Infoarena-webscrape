#include <bits/stdc++.h>
using namespace std;
FILE*f=fopen("cmlsc.in","r");
ofstream fout("cmlsc.out");

int a[1100][1100],n,m,v1[1100],v2[1100],sir[1100];


int main()
{
    int i,j;
    fscanf(f,"%d%d",&n,&m);
    for(i=1;i<=n;i++)
        fscanf(f,"%d",&v1[i]);
    for(j=1;j<=m;j++)
        fscanf(f,"%d",&v2[j]);
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
    {
        if(v1[i]==v2[j])
            a[i][j]=a[i-1][j-1]+1;
        else
            a[i][j]=max(a[i-1][j],a[i][j-1]);
    }
    int bst=0;
    for(i=n,j=m;i>=1;)
    {
        if(v1[i]==v2[j])
        sir[++bst]=v1[i],i--,j--;
        else
            if(a[i-1][j]<a[i][j-1])
            --j;
        else
            --i;
    }
    fout<<bst<<'\n';
    for(i=bst;i>=1;i--)
        fout<<sir[i]<<" ";
    return 0;
}
