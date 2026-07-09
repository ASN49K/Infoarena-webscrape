#include <cstdio>

int N,M;
int v1[1030], v2[1030];
int m[1030][1030];

void citire() {
    scanf("%d %d", &N, &M);
    for (int i=1; i<=N; ++i) scanf("%d", &v1[i]);
    for (int i=1; i<=M; ++i) scanf("%d", &v2[i]);
}

void cmlsc() {
    for (int i=1; i<=N; ++i)
        for (int j=1; j<=M; ++j) {
            if (v1[i] == v2[j]) m[i][j] = m[i-1][j-1]+1;
            else m[i][j] = (m[i-1][j]>m[i][j-1])? m[i-1][j]: m[i][j-1];
        }
}

void elem(int i, int j) {
    if (m[i][j]==0) return;
    if (v1[i]==v2[j]) {
        elem(i-1,j-1);
        printf("%d ",v1[i]);
    } else if (m[i-1][j]==m[i][j]) elem(i-1, j);
    else elem(i,j-1);
}

int main () {

    freopen("cmlsc.in","rt",stdin);
    freopen("cmlsc.out","wt",stdout);

    citire();
    cmlsc();
    printf("%d\n", m[N][M]);
    elem(N,M);

    return 0;
}
