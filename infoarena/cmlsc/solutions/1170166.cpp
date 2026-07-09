#include <iostream>
#include <fstream>
#define nmax 1030
using namespace std;

int main(){
    
    ifstream in("cmlsc.in");
    ofstream out("cmlsc.out");
    
    int n, m, i, j, k;
    int A[nmax], B[nmax], V[nmax];
    int DP[nmax][nmax];
    
    in >> n >> m;
    
    for (i=1; i<=n; i++)
        in >> A[i];
    
    for (i=1; i<=m; i++)
        in >> B[i];
    
    for (i=1; i<=n; i++)
        for (j=1; j<=m; j++)
            if (A[i] == B[j]) DP[i][j] = DP[i-1][j-1] + 1;
            else DP[i][j] = max(DP[i-1][j], DP[i][j-1]);
    
    cout << DP[n][m] << "\n";
    
    i = n, j = m;
    
    while (DP[i][j])
        
        if (DP[i-1][j] == DP[i][j]) i--;
        else if (DP[i][j-1] == DP[i][j]) j--;
        else
            V[++k] = A[i],
            i--, j--;
    
    for (i=DP[n][m]; i>0; i--)
        out << V[i] << " ";
        
    out << "\n";
    
    return 0;
}
