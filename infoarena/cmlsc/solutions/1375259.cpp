#include <fstream>
#define NMAX 1030

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int M,N,XValue[NMAX],YValue[NMAX],DP[NMAX][NMAX];


void Read(){
    f>>N>>M;
    for (int i = 1; i <= N; i++) {
        f>>XValue[i];
    }
    for (int i = 1; i <= M; i++) {
        f>>YValue[i];
    }
}

void Solve(){
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            DP[i][j] = max(DP[i-1][j], DP[i][j-1]);
            if (XValue[i] == YValue[j]) {
                DP[i][j] = max(DP[i][j], DP[i-1][j-1]+1);
            }
        }
    }
}

void Recreate(int n, int m){
    if (n == 0 || m == 0) {
        return;
    }
    if (XValue[n] == YValue[m]) {
        Recreate(n-1, m-1);
        g<<XValue[n]<<" ";
    }else if (DP[n][m-1] > DP[n-1][m]) {
        Recreate(n,m-1);
    }else{
        Recreate(n-1,m);
    }
}

void Write(){
    g<<DP[N][M]<<"\n";
    Recreate(N,M);
}

int main() {

    Read();
    Solve();
    Write();
    
    return 0;
}
