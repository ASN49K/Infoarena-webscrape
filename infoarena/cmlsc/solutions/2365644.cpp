#include <fstream>

#define maxim(a, b) ((a > b) ? a : b)
#define NMax 1024

using namespace std;

int m, n;
int A[NMax], B[NMax];
int dp[NMax][NMax], sir[NMax], bst;

int main() {
    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");

    fin>>m>>n;

    for(int i=1;i<=m;i++)
        fin>>A[i];

    for(int i=1;i<=n;i++)
        fin>>B[i];

    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            if (A[i] == B[j])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = maxim(dp[i - 1][j], dp[i][j - 1]);

    for (int i = m, j = n; i;) {
        if (A[i] == B[j])
            sir[++bst] = A[i], i--, j--;
        else if (dp[i - 1][j] < dp[i][j - 1])
            j--;
        else
            i--;
    }

    fout<<bst<<"\n";
    for (int i = bst; i; i--)
        fout<<sir[i]<<" ";

    return 0;
}