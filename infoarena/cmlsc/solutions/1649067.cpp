#include <bits/stdc++.h>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int NMax = 1050;

int A[NMax], B[NMax], S[NMax];
int D[NMax][NMax];

int main(){
    int n, m;
    fin >> n >> m;
    for(int i = 1; i <= n; i++){
        fin >> A[i];
    }
    for(int i = 1; i <= m; i++){
        fin >> B[i];
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(A[i] == B[j]){
                D[i][j] = 1 + D[i - 1][j - 1];
            } else {
                D[i][j] = max(D[i - 1][j], D[i][j - 1]);
            }
        }
    }
    int x = 1, y = 1;
    int k = 0;
    while(x <= n && y <= m){
        if(A[x] == B[y]){
            S[++k] = A[x];
            x++; y++;
        } else {
            if(D[x + 1][y] > D[x][y + 1]){
                y++;
            } else {
                x++;
            }
        }
    }
    fout << k << "\n";
    for(int i = 1; i <= k; i++) fout << S[i] << " ";
    return 0;
}
