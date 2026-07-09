#include <bits/stdc++.h>
using namespace std;
ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");
const int Nmax = 1030;
int v[Nmax], f[Nmax], A[Nmax][Nmax], P[Nmax][Nmax][3], maxx = 0, ci, cj, r[Nmax], k;
int32_t main()
{
    int n, m;
    fin >> n >> m;
    for(int i = 1; i <= n; i ++) {
        fin >> v[i];
    }
    for(int i = 1; i <= m; i ++) {
        fin >> f[i];
    }
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            if(v[i] == f[j]) {
                A[i][j] = A[i - 1][j - 1] + 1;
                P[i][j][1] = -1;
                P[i][j][2] = -1;
                maxx = A[i][j];
                ci = i;
                cj = j;

            }
            else {
                if(A[i][j - 1] > A[i - 1][j]) {
                    A[i][j] = A[i][j - 1];
                    P[i][j][2] = -1;
                }
                else {
                    A[i][j] = A[i - 1][j];
                    P[i][j][1] = -1;
                }
            }
        }
    }
    fout << maxx << '\n';
    for(int i = ci, j = cj; A[i][j] > 0; ) {
        if(P[i][j][1] == -1 && P[i][j][2] == -1) {
            r[++ k] = v[i];
        }
        i += P[i][j][1];
        j += P[i][j][2];
    }
    for(int i = k; i >= 1; i --) {
        fout << r[i] << " ";
    }
    return 0;
}
