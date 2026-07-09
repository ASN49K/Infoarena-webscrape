#include <fstream>
#include <vector>
using namespace std;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
vector<vector<long long>>V;
vector<long long > A;
vector<long long > B;
void recursiv(long long i,long long j) {
    if (i > 0 && j > 0) {
        if (A[i] == B[j]) {
            recursiv(i - 1, j - 1);
            cout << A[i] << ' ';
        }
        else {
            if (V[i][j - 1] > V[i - 1][j]) {
                recursiv(i, j - 1);
            }
            else recursiv(i - 1, j);
        }
    }
}
int main()
{
    long long n,i,m,j;
    cin >> n >> m;
    A.resize(n+1);
    for (i = 1; i <= n; i++) {
        cin >> A[i];
    }
    B.resize(m+1);
    for (i = 1; i <= m; i++) {
        cin >> B[i];
    }
    V.resize(n + 1, vector<long long>(m + 1));
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            if (A[i] == B[j]) {
                V[i][j] = 1 + V[i - 1][j - 1];
            }
            else {
                V[i][j] = max(V[i - 1][j], V[i][j - 1]);
            }
        }
    }
    cout << V[n][m] << '\n';
    recursiv(n, m);

}