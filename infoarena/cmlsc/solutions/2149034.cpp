#include <fstream>
#include <algorithm>

using namespace std;

ifstream in ("cmlsc.in");
ofstream out ("cmlsc.out");

const int N = 1100;
int A[N], B[N], l[N][N], sol[N];

int main()
{
    int m, n, i, j;
    in >> m >> n;
    for(i = 1; i <= m; i++)
        in >> A[i];
    for(i = 1; i <= n; i++)
        in >> B[i];
    for(i = 1; i <= m; i++)
        for(j = 1; j <= n; j++)
            if(A[i] == B[j])
                l[i][j] = l[i-1][j-1] + 1;
            else
                l[i][j] = max(l[i][j-1], l[i-1][j]);
    out << l[m][n] <<"\n";
    int k = l[m][n];
    for(i = m; i >= 1; i--)
        for(j = n; j >= 1; j--)
            if(A[i] == B[j] && l[i][j] == k)
            {
                sol[k] = A[i];
                k--;
            }
    for(i = 1; i <= l[m][n]; i++)
        out << sol[i] << " ";
    return 0;
}
