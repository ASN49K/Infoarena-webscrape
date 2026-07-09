#include<fstream>
#include<iostream>
#include<vector>
#define NMAX 1029
using namespace std;

int n,m,A[NMAX],B[NMAX],DP[NMAX][NMAX];

ofstream f1("cmlsc.out");

void write(int i, int j) {
    if(i == 0 || j == 0)
        return;

    if(A[i] == B[j]) {
        write(i - 1, j - 1);
        f1<<A[i]<<" ";
    } else if(DP[i][j] == DP[i - 1][j])
        write(i - 1, j);
    else
        write(i, j - 1);
}

int main() {
    ifstream f("cmlsc.in");
    int i, j;
    f>>n>>m;
    for(i = 1; i <= n; i++)
        f>>A[i];
    for(i = 1; i <= m; i++)
        f>>B[i];

    for(i = 1; i <= n; i++)
        for(j = 1; j <= m; j++)
            if(A[i] == B[j])
                DP[i][j] = DP[i - 1][j - 1] + 1;
            else
                DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);

    f1<<DP[n][m]<<"\n";

    write(n, m);

    return 0;
}
