#include<cstdio>
using namespace std;
FILE *f=fopen("cmlsc.in","r");
FILE *g=fopen("cmlsc.out","w");
int m, n, v[1025],w[1025],a[1025][1025],x[1025],k,i,j;
int main()
{
    fscanf(f,"%d %d",&n,&m);
    for(i=1;i<=n;i++)fscanf(f,"%d",&v[i]);
    for(i=1;i<=m;i++)fscanf(f,"%d",&w[i]);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(v[i]==w[j])a[i][j]=a[i-1][j-1]+1;
            else
            {
                if(a[i-1][j]>a[i][j-1])a[i][j]=a[i-1][j];
                else a[i][j]=a[i][j-1];
            }
        }
    }
    i=n;
    j=m;
    while(i>0&&j>0)
    {
        if(v[i]==w[j])
        {
            x[++k]=v[i];
            i--;
            j--;
        }
        else
        {
            if(a[i][j]==a[i-1][j])i--;
            else j--;
        }
    }
    fprintf(g,"%d\n",k);
    for(i=k;i>=1;i--)fprintf(g,"%d ",x[i]);
    fclose(f);
    fclose(g);
    return 0;
}
