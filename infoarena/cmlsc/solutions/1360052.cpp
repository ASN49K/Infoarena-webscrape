#include<cstdio>
#include<string>

using namespace std;

#ifdef HOME
const string inputFile = "input.txt";
const string outputFile = "output.txt";
#else
const string problemName = "cmlsc";
const string inputFile = problemName + ".in";
const string outputFile = problemName + ".out";
#endif

typedef pair<int, int> PII;
const int NMAX = 1024 + 5;

int N, M;
int A[NMAX];
int B[NMAX];
int D[NMAX][NMAX];
PII dad[NMAX][NMAX];

void scrie(int x, int y) {
    if(!x || !y)
        return;

    scrie(dad[x][y].first, dad[x][y].second);

    if(dad[x][y] == make_pair(x - 1, y - 1))
        printf("%d ", A[x]);
}

int main() {
    int i, j;

    freopen(inputFile.c_str(), "r", stdin);
    freopen(outputFile.c_str(), "w", stdout);

    scanf("%d%d", &N, &M);

    for(i = 1; i <= N; i++)
        scanf("%d", &A[i]);

    for(i = 1; i <= M; i++)
        scanf("%d", &B[i]);

    for(i = 1; i <= N; i++)
        for(j = 1; j <= M; j++)
            if(A[i] == B[j]) {
                D[i][j] = D[i - 1][j - 1] + 1;
                dad[i][j] = make_pair(i - 1, j - 1);
            } else {
                if(D[i][j - 1] > D[i - 1][j]) {
                    D[i][j] = D[i][j - 1];
                    dad[i][j] = make_pair(i, j - 1);
                } else {
                    D[i][j] = D[i - 1][j];
                    dad[i][j] = make_pair(i - 1, j);
                }
            }

    printf("%d\n", D[N][M]);

    scrie(N, M);

    return 0;
}
