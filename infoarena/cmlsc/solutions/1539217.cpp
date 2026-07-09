#include <fstream>
#define N  1025
using namespace std;
ifstream f ("cmlsc.in");
ofstream g ("cmlsc.out");

int v1[N], v2[N], x[N][N], s[N];
int i,j,n,m;

int main()
{

    f >> n >> m;
    for (i = 1; i <= n; i++)
        f >> v1[i];
    for (i = 1; i <= m; i++)
        f >> v2[i];

    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
        {
            if (v1[i] == v2[j])
                x[i][j] = x[i - 1][j - 1] + 1;
            else
                x[i][j] = max(x[i - 1][j], x[i][j - 1]);
        }
    int k = 0;
    i = n; j = m;
    while (i > 0)
    {
        if (v1[i] == v2[j])
        {
            s[++k] = v1[i];
            i--;
            j--;
        }
        else if (x[i-1][j] > x[i][j-1]) i--;
        else j--;
    }


    g << x[n][m] << endl;
    for (i = k; i >= 1; i--)
      g << s[i] << " ";

   return 0;
}
