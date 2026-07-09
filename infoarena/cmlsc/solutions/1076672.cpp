#include <fstream>
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
const int N=1024;
int a[N], b[N],nr, sol[N], c[N][N],n,m;
inline int maxim(int a, int b)
{
    return (a>b)? a: b;
}
int main()
{
    in >> m >> n;
    for(int i=1;i<=m;i++)
        in >> a[i];
   // out << a[2];
    for(int i=1;i<=n;i++)
        in >> b[i];
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            if(a[i] == b[j])
                c[i][j] = c[i-1][j-1] +1;
            else
                c[i][j] = maxim(c[i-1][j], c[i][j-1]);
    for(int i=m,j=n;i; )
        if(a[i] == b[j])
        {
            sol[++nr] = a[i];
            --i;
            --j;
        }
        else
            if(c[i-1][j] > c[i][j-1])
                --i;
            else
                --j;
    out << nr << '\n';
    for(int i=nr;i;i--)
        out << sol[i] << " ";
    return 0;
}
