#include <cstdio>

using namespace std;
const int N=1025;
int a[N],b[N],d[N][N],ras[N];
int max(int x,int y)
{
    if(x>=y)
        return x;
    else
        return y;
}
int main()
{
    FILE *in,*out;
    in=fopen("cmlsc.in","r");
    out=fopen("cmlsc.out","w");
    int n,m,i,j,bst=0;
    fscanf(in,"%d%d",&n,&m);
    for(i=1;i<=n;i++)
        fscanf(in,"%d",&a[i]);
    for(j=1;j<=m;j++)
        fscanf(in,"%d",&b[j]);
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {
            if(a[i]==b[j])
                d[i][j]=1+d[i-1][j-1];
            else
                d[i][j]=max(d[i][j-1],d[i-1][j]);
        }
    i=n;
    j=m;
    while(i>0 && j>0)
    {
        if(a[i]==b[j])
        {
            bst++;
            ras[bst]=a[i];
            i--;
            j--;
        }
        if(d[i-1][j]<d[i][j-1])
            j--;
        else
            i--;
    }
    fprintf(out,"%d\n",bst);
    for(i=bst;i>=1;i--)
        fprintf(out,"%d ",ras[i]);
    return 0;
}
