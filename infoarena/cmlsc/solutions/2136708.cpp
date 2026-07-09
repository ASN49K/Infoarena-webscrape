#include <bits/stdc++.h>

using namespace std;

ifstream Cin("cmlsc.in");
ofstream Cout("cmlsc.out");

int N, M, a[1043], b[1043], v[1043][1043];

void reconst(int x, int y);

int main() {
    Cin >> N >> M;
    for(int i = 1; i <= N; i++)
        Cin >> a[i];
    for(int i = 1; i <= M; i++)
        Cin >> b[i];
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= M; j++)
            if(a[i] == b[j]) v[i][j] = 1 + v[i - 1][j - 1];
            else v[i][j] = max(v[i - 1][j], v[i][j - 1]);
    Cout << v[N][M] << "\n";
    reconst(N, M);
    Cout << "\n";
    return 0;
}

void reconst(int x, int y) {
    if(x < 1 || y < 1) return;
    if(a[x] == b[y]) {
        reconst(x - 1, y - 1);
        Cout << a[x] << " ";
    }
    else if(v[x - 1][y] > v[x][y - 1]) reconst(x - 1, y);
    else reconst(x, y - 1);
}