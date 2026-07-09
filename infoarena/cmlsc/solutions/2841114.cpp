#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
long int succ[1030], d[1030][1030], a[1030], b[1030], rez[1030];
int n, m, cnt;
int main() {
    in >> n >> m;
    for (int i = 0; i < n; i++) in >> a[i];
    for (int i = 0; i < m; i++) in >> b[i];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (a[i - 1] == b[j - 1]) d[i][j] = d[i - 1][j - 1] + 1, succ[i] = j;
            else d[i][j] = max(d[i - 1][j], d[i][j - 1]);
    for (int i = n; i >= 1;)
    {
        for (int j = m; j >= 1;)
            if (a[i - 1] == b[j - 1]) rez[++cnt] = a[i - 1], i--, j--;
            else if (d[i - 1][j] < d[i][j - 1]) j--;
            else i--;
    }out << d[n][m] << '\n';
    for (int i = cnt; i >= 1; i--)
        out << rez[i] << " ";
    return 0;
}