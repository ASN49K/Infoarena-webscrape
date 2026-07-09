#include <fstream>
using namespace std;
#define max(a,b) ((a>b)? a : b)
#define FOR(a,b,c) for (int a=b;a<=c;a++)
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
const int nmax=1050;
int n,m,a[nmax],b[nmax],d[nmax][nmax],c[nmax];

int main()
{
    cin>>n>>m;

    for (int i=1;i<=n;i++)
        cin>>a[i];
    for (int i=1;i<=m;i++)
        cin>>b[i];
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
         if (a[i]==b[j]) d[i][j]=d[i-1][j-1]+1;
            else d[i][j]=max(d[i-1][j],d[i][j-1]);

   /* int i,j;
    FOR (i,1,n) {
        FOR (j,1,m)
           cout<<d[i][j];
        cout<<"\n";*/



    int x=d[n][m];
    cout<<x<<"\n";
    while (n && m)
    {
        if (a[n]==b[m]) {
             c[d[n][m]]=a[n];
             n--; m--;
        }
        else if (d[n][m-1]>d[n-1][m]) m--; else n--;
    }
    for (int i=1;i<=x;i++)
        cout<<c[i]<<" ";
}
