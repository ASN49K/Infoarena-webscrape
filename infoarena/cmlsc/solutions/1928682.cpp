#include <fstream>
#include <vector>
#include <iostream>
#define nmax 1027
using namespace std;
int a[nmax], b[nmax], q[nmax][nmax];
vector <int> sol;
int main()
{
    ifstream f("clmsc.in");
    ofstream g("clmsc.out");
    int m, n, i, j;
    f >> m >> n;
    for (i = 1; i <= m; ++i)
        f >> a[i];
    for (i = 1; i <= n; ++i)
        f >> b[i];

    for (i = 1; i <= m; ++i)
        for (j = 1; j <= n; ++j)
            if (a[i] == b[j])
                q[i][j] = q[i-1][j-1]+1;
            else q[i][j] = max (q[i-1][j], q[i][j-1]);

    for (i = m, j =n; i;)
        if (a[i] == b[j]) {
            sol.push_back(a[i]); --i; --j;
        }
        else if (q[i-1][j] < q[i][j-1])
            --j;
        else
            --i;
        g << sol.size() << "\n";
        for (vector < int > :: reverse_iterator it = sol.rbegin(); it != sol.rend(); ++it)
            g << (*it) << " ";
    return 0;
}
