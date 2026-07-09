#include <cstdio>
#define MAX 1026
using namespace std;
int a[MAX],b[MAX],d[MAX],cnt;
int c[MAX][MAX];
int bk(int i, int j)
{
    if(i==0 || j==0)
        return 0;
    else if(a[i]==b[j])
    {
            d[++cnt]=a[i];
            return bk(i-1,j-1) +a[i];
            }
    else if(c[i][j-1]>c[i-1][j])
        return bk(i,j-1);
        else return bk(i-1,j);
}
int max(int a, int b)
{
    if(a>b)
        return a;
    else return b;
}

int main()
{
    FILE *fin,*fout;
    fin=fopen("cmlsc.in","r");
    fout=fopen("cmlsc.out","w");
    int n,m;
    fscanf(fin,"%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        fscanf(fin,"%d",&a[i]);
    for(int i=1;i<=m;i++)
        fscanf(fin,"%d",&b[i]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if(a[i]==b[j])
            {
                c[i][j]=c[i-1][j-1]+1;

            }
            else
                c[i][j]=max(c[i][j-1],c[i-1][j]);
        }
    bk(n,m);
    fprintf(fout,"%d\n",c[n][m]);
    for(int i=cnt;i>0;i--)
        fprintf(fout,"%d ", d[i]);
    return 0;
}
