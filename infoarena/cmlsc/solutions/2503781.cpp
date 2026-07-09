#include <iostream>
#include <fstream>
#define NMAX 1024
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n, m, a[NMAX + 1], b[NMAX + 1], c[NMAX + 1][NMAX + 1], i, j;
void traseu(int i, int j) {
    if(c[i][j] != 0) {
        if(a[i] == b[j]) {
            traseu(i - 1, j - 1);
            cout << a[i] << " ";
        } else {
            if(c[i - 1][j] > c[i][j - 1])
                traseu(i - 1, j);
            else
                traseu(i, j - 1);
        }
    }
}
int main() {
    fin >> n >> m;
    for(i = 1; i <= n; i++)
        fin >> a[i];
    for(i = 1; i <= m; i++)
        fin >> b[i];
    for(i = 1; i <= n; i++)
        for(j = 1; j <= m; j++) {
            if(a[i] == b[j])
                c[i][j] = c[i - 1][j - 1] + 1;
            else
                c[i][j] = max(c[i - 1][j], c[i][j - 1]);
        }
    cout<<c[n][m]<<endl;
    traseu(n, m);
    return 0;
}
