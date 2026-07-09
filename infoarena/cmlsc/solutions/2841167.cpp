#include <iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<fstream>
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int n, m, cnt;
int a[1024], b[1024], rez[1024];
int d[1024][1024];
int main()
{
    in >> n >> m;
    for (int i = 1; i <= n; i++) in >> a[i];
    for (int i = 1; i <= m; i++) in >> b[i];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            if (a[i] == b[j]) d[i][j] = d[i - 1][j - 1] + 1;
            else d[i][j] = max(d[i - 1][j], d[i][j - 1]);
        }
    for (int i = n; i;) {
        for (int j = m; i;) {
            if (a[i] == b[j]) rez[++cnt] = a[i], i--, j--;
            else if (d[i - 1][j] < d[i][j - 1]) j--;
            else i--;
        }
    }
    out << d[n][m] << '\n';
    for (int i = cnt; i >= 1; i--) out << rez[i] << " ";
    return 0;
}