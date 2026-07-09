#include <fstream>
#define nmax 1025

using namespace std;

ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");

int n,i,j,nr=0,m,a[nmax],b[nmax],c[nmax];

int main()
{
    cin>>n>>m;
    for(i=1;i<=n;i++)
    cin>>a[i];
    for(j=1;j<=m;j++)
    cin>>b[j];
    for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
    if(a[i]==b[j])
    c[i]=a[i];
    for(i=1;i<=n;i++)
    if(c[i]!=0)
    {
        nr++;
    }
    cout<<nr<<"\n";
    for(i=1;i<=n;i++)
    if(c[i]!=0)
    {
        cout<<c[i]<<' ';
    }
    return 0;
}
