#include <fstream>
#include <algorithm>

using namespace std;

#define inFile "cmlsc.in"
#define outFile "cmlsc.out"
#define MAX_N 1025

int A[MAX_N], B[MAX_N];
int D[MAX_N][MAX_N];
int seq[MAX_N], nSeq;

int main() {
    ifstream in(inFile);
    ofstream out(outFile);

    int n, m, i, j;

    in >> n >> m;
    for(i = 1; i <= n; i++) in >> A[i];
    for(i = 1; i <= m; i++) in >> B[i];

    for(i = 1; i <= n; i++) {
        for(j = 1; j <= m; j++) {
            if(A[i] == B[j])
                D[i][j] = D[i-1][j-1] + 1;
            else
                D[i][j] = max(D[i-1][j], D[i][j-1]);
        }
    }

    out << D[n][m] << '\n';
    i = n; j = m;
    while(i && j) {
        if(A[i] == B[j]) {
            seq[++nSeq] = A[i];
            i--;
            j--;
        }
        else if(D[i-1][j] > D[i][j-1]) i--;
        else j--;
    }

    for(i = nSeq; i; i--) out << seq[i] << ' ';

    return 0;
}
