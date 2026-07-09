using namespace std;
#include<stdio.h>
const int N=1025;
int m,n,a[N],b[N],mat[N][N],v[N];
void x(int i,int j), y(int i, int j);
void citire()
{
    freopen("cmlsc.in", "r",stdin);
    freopen("cmlsc.out", "w",stdout);
    scanf("%d%d", &m, &n);
    for(int i=1;i<=m;++i)
        scanf("%d", &a[i]);
    for(int i=1;i<=n;++i)
        scanf("%d", &b[i]);
}

int max(int a, int b)
{
    if(a>b)
        return a;
    return b;
}

void rezolvare()
{
    int i,j;
    for( i=1;i<=m;++i)
        for( j=1;j<=n;++j)
            if(a[i]==b[j])
                mat[i][j]=mat[i-1][j-1]+1;
            else
                mat[i][j]=max(mat[i][j-1],mat[i-1][j]);
    printf("%d\n",mat[m][n]);
    int nr=0;i=m;j=n;
    while(mat[i][j])
        if(a[i]==b[j])
            {i--;j--;v[++nr]=a[i];}
        else
            if(mat[i][j-1]>mat[i-1][j])
                j--;
            else
                i--;
    while(nr)printf("%d ",v[nr--]);
}

int main()
{
    citire();
    rezolvare();
    return 0;
}
