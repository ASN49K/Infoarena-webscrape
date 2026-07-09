#include <fstream>

using namespace std;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
int a[1030], b[1030], d[1030][1030], cnt, i, j, sir[1030], n, m;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int j = 1; j <= m; j++)
        cin >> b[j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++){
            if (a[i] == b[j])
                d[i][j] = 1 + d[i - 1][j - 1];
            else
                d[i][j] = max(d[i - 1][j], d[i][j - 1]);
        }
    i = n, j = m;
    while (i > 0 && j > 0){
        if (a[i] == b[j]){
            sir[++cnt] = a[i];
            i--;
            j--;
        }
        else if(d[i - 1][j] < d[i][j - 1])
            j--;
        else
            i--;
    }
    cout << cnt << '\n';
    for (int i = cnt; i >= 1; i--)
        cout << sir[i] << " ";
    return 0;
}
