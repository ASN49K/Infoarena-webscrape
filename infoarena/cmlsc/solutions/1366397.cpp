#include <iostream>
#include <fstream>
#include <stack>
#define nmax 1025

using namespace std;

int n, m;
int A[nmax], B[nmax], C[nmax][nmax];
stack <int> S;

int main() {

    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");
    
    fin >> n >> m;
    
    for (int i = 1; i <= n; i++)
        fin >> A[i];
    for (int j = 1; j <= m; j++)
        fin >> B[j];
    
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (A[i] == B[j])
                C[i][j] = C[i-1][j-1] + 1;
            else
                C[i][j] = max(C[i-1][j], C[i][j-1]);
    
    cout << C[n][m] << "\n";
    
    int i = n, j = m;
    
    while (i != 0 && j != 0) {
        
        if (C[i][j-1] == C[i][j])
            j--;
        else if (C[i-1][j] == C[i][j])
            i--;
        else {
            S.push(A[i]);
            i--, j--;
        }
    }
    
    for (; S.size();) {
        fout << S.top() << " ";
        S.pop();
    }
    
    fin.close();
    fout.close();
    
    return 0;
}