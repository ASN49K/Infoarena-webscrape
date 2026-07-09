#include <fstream>
#include <algorithm>
using namespace std;
int a[1025],b[1025],q[1025][1025],s[1025],i,j,n,m,h;
int main()
{
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");
    f>>n;
    f>>m;
    for (i=1;i<=n;i++) f>>a[i];
    for (i=1;i<=m;i++) f>>b[i];
    for (i=1;i<=n;i++)
       for (j=1;j<=m;j++)
           if (a[i]==b[j])
               q[i][j]=q[i-1][j-1]+1;
           else q[i][j] = max(q[i-1][j], q[i][j-1]);
    for (i=n;i>=1;i--)
       for (j=m;j>=1;j--)
        {
            if (a[i]==b[j])
                {s[++h]=a[i];i--;j--;}
            else {
        if (q[i-1][j] < q[i][j-1])
            j--;
        else
            i--;}
        }
        g<<h;g<<'\n';
    for (i=h;i>=1;i--) g<<s[i]<<" ";
    f.close();
    g.close();
    return 0;
}
