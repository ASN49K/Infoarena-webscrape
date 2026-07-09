#include <iostream>
#include <fstream>
#define dimm 1030

std::ifstream f("cmlsc.in");
std::ofstream g("cmlsc.out");

int N, M;
int v1[dimm], v2[dimm];
int tabel[dimm][dimm];

void traceback(int y=N, int x=M, int t=tabel[N][M]) {
	if (y==0) return;
	if (x==0) return;
	if (v1[y] == v2[x]) {
		traceback  (y-1, x-1, t-1);
		g << v1 [y] << ' ';
	}
	else if (tabel [y-1][x] > tabel [x][y-1])
        traceback (y-1, x, t-1);
    else traceback (y, x-1, t-1);
}

void citire() {
    f >> N >> M;
    for (int i=0; i<N; i++)
        f >> v1[i+1];
    for (int i=0; i<M; i++)
        f >> v2[i+1];
}
void rezolvare() {
    for (int i=1, j, mx; i<=N; i++) {
        for (j=1; j<=M; j++) {
            mx = std::max(tabel[i][j-1], tabel[i-1][j]);
            if(v1[i] == v2[j]) mx++;
            tabel[i][j] = mx;
        }
    } g << tabel[N][M] << '\n';
    traceback();
}

int main() {
    citire();
    rezolvare();

    return 0;
}
    