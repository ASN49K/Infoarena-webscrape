#include <iostream>
#include <fstream>

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int n, m, i, j, a[1025], b[1025], d[1025][1025], k = 0, sir[1025];

int maxim(int a, int b) {
    if(a < b)
        return b;
    else return a;
}

int main()
{
    in >> n >> m;
    for(i = 1; i <= n; i++)
        in >> a[i];

    for(j = 1; j <= m; j++)
        in >> b[j];

    for(i = 1; i <= n; i++) {
        for(j = 1; j <= m; j++) {
            if (a[i] == b[j])
                d[i][j] = 1 + d[i-1][j-1];
            else
                d[i][j] = maxim(d[i-1][j], d[i][j-1]);
        }
    }

    for(i = n; i >= 1; i--) {
        for(j = m; j >= 1; j--) {
            if (a[i] == b[j]) {
                sir[++k] = a[i];
                i--;
                j--;
            } else if(d[i - 1][j] < d[i][j - 1]) {
                j--;
            } else {
                i--;
            }
        }
    }

    out << k << "\n";
    for(i = k; i >= 1; i--)
        out << sir[i] << " ";

    return 0;
}
