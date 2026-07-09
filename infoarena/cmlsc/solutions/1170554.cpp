#include <fstream>
using namespace std;

ifstream is ("cmlsc.in");
ofstream os ("cmlsc.out");

int n, m, d[1025][1025], a[1025], b[1025], x[1025], nr;
int main()
{
    is >> n >> m;
    for(int i = 1; i <= n; ++i)
        is >> a[i];
    for(int i = 1; i <= m; ++i)
        is >> b[i];
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
        {
            if(a[i] == b[j])
                d[i][j] = d[i-1][j-1] + 1;
            else
                d[i][j] = max(d[i-1][j], d[i][j-1]);
        }
    int i = n, j = m;
    while(i)
    {
        if(a[i] == b[j])
            x[++nr] = a[i], i--, j--;

        else
            if(d[i-1][j] < d[i][j-1])
                j--;
            else
                i--;
    }

    os << nr << '\n';
    for(int i = nr; i >= 1; --i)
        os << x[i] << ' ';

    is.close();
    os.close();
    return 0;
}
