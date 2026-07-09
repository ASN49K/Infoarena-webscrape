#include <fstream>
#include <vector>
#include <algorithm>

#define Nmax 1080

using namespace std;

int N, M, A[Nmax], B[Nmax], DP[Nmax][Nmax];
vector <int> Solution;

void Solve() {

    int i, j;

    for(i = 1; i <= N; i++)
        for(j = 1; j <= M; j++)
            if(A[i] == B[j])
                DP[i][j] = DP[i - 1][j - 1] + 1;
            else
                DP[i][j] = max(DP[i][j - 1], DP[i - 1][j]);

    for(i = N, j = M; i > 0 && j > 0;)
        if(A[i] == B[j]) {
            Solution.push_back(A[i]);
            i--; j--;
        } else if(DP[i][j - 1] > DP[i - 1][j])
            j--;
        else
            i--;

    reverse(Solution.begin(), Solution.end());
}
void Read() {

    int i;
    ifstream in("cmlsc.in");
    in >> N >> M;

    for(i = 1; i <= N; i++)
        in >> A[i];

    for(i = 1; i <= M; i++)
        in >> B[i];

    in.close();
}
void Write() {

    ofstream out("cmlsc.out");
    out << DP[N][M] << '\n';

    for(int i = 0; i < Solution.size(); i++)
        out << Solution[i] << ' ';

    out << '\n';
    out.close();
}
int main() {

    Read();
    Solve();
    Write();

    return 0;
}
