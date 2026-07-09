#include <iostream>
#include <fstream>

using namespace std;

#define maxim(a, b) ((a > b) ? a : b)

int main()
{
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");
    int M, N;
    f>>M>>N;
    int *a = new int[M+1];
    int *b = new int[N+1];
    for (int i = 1; i <= M; i++){
        f>>a[i];
    }

    for (int i = 1; i <= N; ++i) {
        f>>b[i];
    }

    int **dp = new int*[M+1];
    for (int i = 0; i <= M; ++i){
        dp[i] = new int[N+1];
    }

    for (int i = 1; i <= M; ++i ) {
        for ( int j = 1; j <= N; ++j ) {
            if (a[i] == b[j]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = maxim(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    int index = 0;
    int *lcs = new int[dp[M][N]];
    int i,j;
    for (i = M, j = N; i && j; ) {
        if ( a[i] == b[j] ) {
            lcs[index++] = a[i], i--,j--;
        } else if (dp[i-1][j] > dp[i][j-1] ) {
            i--;
        } else {
            j--;
        }
    }

    g<<dp[M][N];
    g<<"\n";
    for ( i = index - 1; i > -1; --i) {
        g<<lcs[i]<<" ";
    }
    f.close();
    g.close();
    return 0;
}
