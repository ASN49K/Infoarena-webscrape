#include <iostream>
#include <fstream>
#include <stack>
#define nmax 1025

using namespace std;

int N, M;
int A[nmax], B[nmax], C[nmax][nmax];
stack <int> S;

int main() {
    
    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");
    
    fin >> N >> M;
    
    for (int i = 1; i <= N; i++)
        fin >> A[i];
    
    for (int j = 1; j <= M; j++)
        fin >> B[j];
    
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            if (A[i] == B[j])
                C[i][j] = C[i-1][j-1] + 1;
            else
                C[i][j] = max(C[i-1][j], C[i][j-1]);
    
    fout << C[N][M] << "\n";
    
    int i = N;
    int j = M;
    
    while (i > 0 && j > 0)
        if (C[i-1][j] != C[i][j] && C[i][j-1] != C[i][j]) {
            S.push(A[i]);
            i--;
            j--;
        } else if (C[i-1][j] == C[i][j])
            i--;
          else
            j--;
    
    while (!S.empty()) {
        fout << S.top() << " ";
        S.pop();
    }
        
    fin.close();
    fout.close();
    
    return 0;
}