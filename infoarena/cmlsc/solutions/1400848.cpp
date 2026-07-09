#include <fstream>

using namespace std;

ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");

int max(int a, int b){
if(a>b) return a;
else return b;}

int main()
{
    int sol[1000][1000],i,j,a[1000],b[1000],n,m;
    cin>>n>>m;
    for(i=1;i<=n;i++) cin>>a[i];
    for(j=1;j<=m;j++) cin>>b[i];

    for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
    if(a[i]==b[j]) sol[i][j]=1+sol[i-1][j-1];
    else sol[i][j]=max(sol[i-1][j],sol[i][j-1]);
    return 0;
}
