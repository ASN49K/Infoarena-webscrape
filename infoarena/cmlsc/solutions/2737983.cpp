#include <fstream>
#include <cmath>

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int n,m,a[1025],b[1025],c[1025][1025],c2[1025],ok;

int main()
{
    in>>n>>m;
    for ( int i=1; i<=n; i++)
        in>>a[i];
    for ( int i=1; i<=m; i++)
        in>>b[i];
    for ( int i=1; i<=n; i++)
        for ( int j=1; j<=m; j++)
            if ( a[i]==b[j])
                c[i][j]=1+c[i-1][j-1];
            else
                c[i][j]=max(c[i-1][j],c[i][j-1]);
    for ( int i=n,j=m; i;)
        if ( a[i]==b[j])
        {
            c2[++ok]=a[i];
            i--;
            j--;
        }
        else if ( c[i-1][j]<c[i][j-1])
            j--;
        else
            i--;
    out<<ok<<'\n';
    for ( int i=ok; i; i--)
        out<<c2[i]<<" ";
    return 0;
}
