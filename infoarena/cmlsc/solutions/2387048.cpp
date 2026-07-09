#include <cstdio>

using namespace std;

int a[1025],b[1025],best[1025][1025],sol[1025];

int max(int a,int b)
{
    if(a>b)
        return a;
    return b;
}

int main()
{
    FILE *f = fopen("cmlsc.in","r");
    FILE *g = fopen("cmlsc.out","w");
    int n,m;
    fscanf(f,"%d %d",&n,&m);
    for(int i=1;i<=n;i++)
        fscanf(f,"%d",&a[i]);
    for(int i=1;i<=m;i++)
        fscanf(f,"%d",&b[i]);

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i] == b[j])
                best[i][j] = best[i-1][j-1] + 1;
            else
                best[i][j] = max(best[i-1][j], best[i][j-1]);
        }
    }

    int i=n,j=m,k=0;
    while(i > 0 && j > 0)
    {
        if(a[i] == b[j])
        {
            sol[k++] = a[i];
            i--;
            j--;
        }
        else if(best[i-1][j] > best[i][j-1])
            i--;
        else
            j--;
    }
    fprintf(g,"%d\n",k);
    for(int i=k-1;i>=0;i--)
        fprintf(g,"%d ",sol[i]);



    return 0;
}
