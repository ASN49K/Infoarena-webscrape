#include <stdio.h>
using namespace std;
FILE * f=fopen("cmlsc.in","r");
FILE * g=fopen("cmlsc.out","w");
int n,m,v1[1025],v2[1025],i,j,a[1025][1025],v[1025],l;
int maxi(int a,int b,int c)
{
    int max;
    if (a>=b && a>=c) max=a;
    else if (b>=a && b>=c) max=b;
    else if (c>=a && c>=b) max=c;
    return max;
}
int main()
{
    fscanf(f,"%d%d",&n,&m);
    for (i=1;i<=n;i++)
       fscanf(f,"%d",&v1[i]);
    for (i=1;i<=n;i++)
       fscanf(f,"%d",&v2[i]);
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=m;j++)
        {
            if (v1[i]==v2[j])
            {
                a[i][j]=a[i-1][j-1]+1;
                l++;
                v[l]=v1[i];
            }
            else
            {
                a[i][j]=maxi(a[i-1][j],a[i][j-1],a[i-1][j-1]);
            }
        }
    }
    fprintf(g,"%d\n",a[n][m]);
    for (i=1;i<=l;i++)
    {
        fprintf(g,"%d ",v[i]);
    }
    return 0;
}
