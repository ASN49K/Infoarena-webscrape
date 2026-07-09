	
#include <fstream>
#include <cstring>
using namespace std;
 
 ifstream cin ("cmlsc.in");
 ofstream cout ("cmlsc.out");
 
int a[1025],b[1025],n,m,d[1025][1025];
 
void citire()
{
    int x;
    cin >> n >> m;
    for(int i=1;i<=n;++i)cin >> a[i];
    for(int i=1;i<=m;++i)cin >> b[i];
}
 
void pd()
{
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            if(a[i] == b[j])
                d[i][j] = 1 + d[i-1][j-1];
            else
                d[i][j] = max(d[i-1][j],d[i][j-1]);
 
    int lmax = d[n][m],i=n,j=m,sol[1025],k=0;
 
    while ( i && j)
    {
        if(a[i] == b[j])
        {
            sol[++k] = a[i];
            i--;
            j--;
 
        }
        else
            if(d[i-1][j] > d[i][j-1])i--;
        else
            j--;
    }
    cout << lmax << '\n';
    for(int i=k;i>=1;--i)cout << sol[i] << ' ';
 
 
 
}
 
int main()
{
     citire();
     pd();
}