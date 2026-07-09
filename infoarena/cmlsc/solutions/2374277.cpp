#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

const int NMax = 1025;
short int N, M, DP[NMax][NMax], A[NMax], B[NMax];
vector <int> Sol;

void Read(){
    in >> N >> M;
    for (int i = 1; i <= N; ++i)
        in >> A[i];
    for (int i = 1; i <= M; ++i)
        in >> B[i];
}

void Solve(){
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j){
            if (A[i] == B[j]){
                DP[i][j] = DP[i-1][j-1] + 1;
                Sol.push_back(A[i]);
            }
            else
                DP[i][j] = max(DP[i-1][j], DP[i][j-1]);
        }
    out << DP[N][M] << '\n';
    for (int i = 0; i < (int)Sol.size(); ++i)
        out << Sol[i] << " ";
}

int main(){
    Read();
    Solve();
    return 0;
}
