#include <fstream>
using namespace std;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
int n, m, a[1050], b[1050], v[1030][1030], sol[1050], k;
int main()
{
    cin >> n >> m;

    for(int i = 1; i <= n; i ++)
        cin >> a[i];
    for(int i = 1; i <= m; i ++)
        cin >> b[i];

    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= m; j ++)
            if(a[i] == b[j])
                v[i][j] = v[i - 1][j - 1] + 1;
            else
                v[i][j] = max(v[i - 1][j], v[i][j - 1]);

    for(int i = n, j = m; i; )
    {
        if(a[i] == b[j])
        {
            sol[++k] = a[i];
            i--;
            j--;
        }
        else if(v[i - 1][j] < v[i][j - 1])
            j--;
        else
            i--;
    }

    cout << k << '\n';

    for(int i = k; i >= 1; i --)
        cout << sol[i] << " ";

    return 0;
}
