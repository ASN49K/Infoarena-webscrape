#include <fstream>

using namespace std;

ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");

int d[1030][1030];
int v1[1030];
int v2[1030];
int sol[1030];

int main()
{
    int n , m , i , j , rez;
    cin >> n >> m;
    for(i = 1; i <= n; i++)
        cin >> v1[i];
    for(i = 1; i <= m; i++)
        cin >> v2[i];
    for(i = 1; i <= n; i++)
        for(j = 1; j <= m; j++)
        {
            if(v1[i] == v2[j])
                d[i][j] = d[i - 1][j - 1] + 1;
            else
                d[i][j] = max(d[i - 1][j] , d[i][j - 1]);
        }
    rez = d[n][m];
    cout << rez << '\n';
    for(i = n, j = m; i >= 1 && j >= 1;)
    {
        if(v1[i] == v2[j])
        {
            sol[rez--] = v1[i];
            i--;
            j--;
        }
        else
        {
            if(d[i - 1][j] >= d[i][j - 1])
                i--;
            else
                j--;
        }
    }
    for(i = 1; i <= d[n][m]; i++)
        cout << sol[i] << " ";
    return 0;
}
