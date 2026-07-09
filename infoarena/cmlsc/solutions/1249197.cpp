#include <fstream>
#include <algorithm>

#define Nmax 1030

using namespace std;

short N, M, Best, A[Nmax], B[Nmax], DP[Nmax][Nmax], Solution[Nmax];

void Solve() {

    int i, j;

    for(i = 1; i <= N; i++)
        for(j = 1; j <= M; j++)
            if(A[i] == B[j])
                DP[i][j] = DP[i - 1][j - 1] + 1;
            else
                DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);

    // Find solution
    for(i = N, j = M; i && j; )
        if(A[i] == B[j])
            Solution[++Best] = A[i--], j--;
        else if(DP[i - 1][j] < DP[i][j - 1])
            j--;
        else
            i--;

    reverse(Solution + 1, Solution + Best + 1);

}
void Read() {

    ifstream in("cmlsc.in");
    in >> N >> M;

    for(int i = 1; i <= N; in >> A[i++]);
    for(int i = 1; i <= M; in >> B[i++]);

    in.close();

}
void Write() {

    ofstream out("cmlsc.out");

    out << Best << '\n';
    for(int i = 1; i <= Best; i++)
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

