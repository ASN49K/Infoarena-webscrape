# include <cstdio>
using namespace std;
int n,m,a[300],b[300],lung[300][300]={0},sol[300],k=0,i,j;
int Max(int a, int b)
{
    if(a>b) return a;
    else return b;
}
int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for(i=0; i<n; ++i) scanf("%d", &a[i]);
    for(i=0; i<m; ++i) scanf("%d", &b[i]);
    // lung[i][j]==cmlsc a0...ai, b0...bj;

    if(a[0]==b[0]) lung[0][0]=1;
    else lung[0][0]=0;

    for(i=1; i<n; ++i)
    if(b[0]==a[i]) lung[i][0]=1;
    else lung[i][0]=lung[i-1][0];

    for(j=1; j<m; ++j)
    if(a[0]==b[j]) lung[0][j]=1;
    else lung[0][j]=lung[0][j-1];

    for(i=1; i<n; ++i)
        for(j=1; j<m; ++j)
        if(a[i]==b[j]) lung[i][j]=lung[i-1][j-1]+1;
        else lung [i][j]=Max(lung[i-1][j],lung[i][j-1]);
    printf("%d\n", lung[n-1][m-1]);
    i=n-1;
    j=m-1;
    while(i>=0 && j>=0)
    {
        if(a[i]==b[j])
        {
            sol[++k]=a[i];
            i--;
            j--;
        }
        else
        if(i>=1 && lung[i][j]==lung[i-1][j])
        i--;
        else j--;
    }
    for(i=k; i>=1; --i) printf("%d ", sol[i]);
}
