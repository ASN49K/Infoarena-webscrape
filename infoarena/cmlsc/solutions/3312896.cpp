#include <bits/stdc++.h>
using namespace std;
ifstream in("cmlsc.in");
ofstream out ("cmlsc.out");
int v[1023], x[1023], d[1024][1024], sol[1023], k = 1;
int n, m;

int main() {
    in >> n >> m;
    for (int i = 1; i <= n; i++) cin >> v[i];
    for (int i = 1; i <= m; i++) cin >> x[i];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (v[i] == x[j])
            {
                d[i][j] = d[i-1][j-1] + 1;
                sol[k++] = v[i];
            }
            else
                d[i][j] = max(d[i-1][j], d[i][j-1]);
        }
    }

    out << d[n][m] << "\n";

    /* 
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            cout << d[i][j] << ' ';
        cout << '\n';
    }
    */
for(int i = 1; i < k; i++)
out << sol[i] <<' ';
    return 0;
}
