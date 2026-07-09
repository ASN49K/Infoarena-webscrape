#include <bits/stdc++.h>

using namespace std;

const int NMAX = 1030;

int M, N;
int V1[NMAX], V2[NMAX];
int d[NMAX][NMAX];
vector<int> R;

int main() {

    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    scanf("%d %d", &M, &N);
    for(int i = 1; i <= M; ++i) {
        scanf("%d", &V1[i]);
    }

    for(int j = 1; j <= N; ++j) {
        scanf("%d", &V2[j]);
    }

    for(int i = 1; i <= M; ++i) {
        for(int j = 1; j <= N; ++j) {
            d[i][j] = max(d[i-1][j], d[i][j-1]);
            if(V1[i] == V2[j]) {
                d[i][j] =  max(d[i-1][j-1] + 1, d[i][j]);
            }
        }
    }

    printf("%d \n", d[M][N]);

    int i = M;
    int j = N;
    while(d[i][j] != 0) {
        while(d[i][j] == d[i][j-1]) {
            j--;
        }
        while(d[i][j] == d[i-1][j]) {
            i--;
        }
        R.push_back(V1[i]);
        i--;
        j--;
    }

    for(int i = R.size() - 1; i >= 0; --i) {
        printf("%d ", R[i]);
    }

    return 0;

}
