#include <fstream>

using namespace std;

const int MAX = 1200;

int N, M;
int V[MAX], W[MAX];
int dp[MAX][MAX];

void citire() {
    ifstream in("cmlsc.in");
    in >> N >> M;
    for(int i = 1; i <= N; i++)
        in >> V[i];
    for(int i = 1; i <= M; i++)
        in >> W[i];
    in.close();
}

void getMatrix() {
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= M; j++) {
            if(V[i] == W[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else 
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
}

ofstream out("cmlsc.out");

void afisare(int X, int Y) {
    if(!X || !Y) return;
    if(X == N && Y == M) {
        out << dp[X][Y] << "\n";
    }
    if(V[X] == W[Y]) {
        afisare(X - 1, Y - 1);
        out << V[X] << " ";
        return;
    }
    if(dp[X - 1][Y] > dp[X][Y - 1])
        afisare(X - 1, Y);
    else 
        afisare(X, Y - 1);
}

int main() {
    citire();
    getMatrix();
    afisare(N, M);
}
