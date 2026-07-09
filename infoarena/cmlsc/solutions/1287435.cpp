#include <fstream>
#include <algorithm>
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int n,m,a[1025],b[1025],s[1025][1025];
int main()
{
    in>>n>>m;
    for(int i=1;i<=n;i++)
        in>>a[i];
    for(int j=1;j<=m;j++)
        in>>b[j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(a[i]==b[j])
                s[i][j]=s[i-1][j-1]+1;
            else
                s[i][j]=max(s[i-1][j],s[i][j-1]);
    out << s[n][m] << '\n';
    out << a[1] << a[2] << '\n';
    out.close();
    return 0;
}
