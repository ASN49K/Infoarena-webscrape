#include <fstream>
using namespace std;

ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");

const int N = 1024;
int n, m;
int a[N + 1], b[N + 1], matrice[N + 1][N + 1], fin[N + 1];

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int j = 1; j <= m; j++)
        cin >> b[j];
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(a[i] != b[j])
                matrice[i][j] = max(matrice[i][j - 1], matrice[i - 1][j]);
            else
                matrice[i][j] = 1 + matrice[i - 1][j - 1];
        }
    }
    cout << matrice[n][m] << "\n";
    int k = 0;
    int cm = m, cn = n;
    while(matrice[cn][cm])
    {
        if(a[cn] == b[cm])
        {
            fin[k++] = b[cm];
            cn--;
            cm--;
        }
        else
            if(a[cn] != b[cm] && matrice[cn - 1][cm] > matrice[cn][cm - 1])
                cn--;
        else
            cm--;
    }
    for(int i = k - 1; i >= 0; i--)
        cout << fin[i] << " ";
    return 0;
}
