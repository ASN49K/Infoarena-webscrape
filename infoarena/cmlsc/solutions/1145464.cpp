#include <fstream>
#define maxim(a, b) ((a > b) ? a : b)
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n,m,A[1025],B[1025],pd[1025][1025],sol[1025];
int main()
{
    f >> n >> m;
    for(int i=1; i<=n; i++) f >> A[i];
    for(int i=1; i<=m; i++) f >> B[i];
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(A[i] == B[j])
            {
                pd[i][j] = 1 + pd[i-1][j-1];
            }
            else
            {
                pd[i][j] = maxim(pd[i-1][j], pd[i][j-1]);
            }
        }
    }

    g << pd[n][m] << '\n';
    int i = n, j = m, k = 0;

    while(i && j)
    {
        if(A[i] == B[j])
        {
            sol[++k] = A[i];
            i--;
            j--;
        }
        else if(pd[i][j] == pd[i-1][j]) i--;
        else                            j--;
    }

    while(k) g << sol[k--] << " ";
    g << '\n';
    g.close();
    return 0;
}
