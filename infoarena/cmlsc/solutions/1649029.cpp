#include <bits/stdc++.h>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int NMax = 1050;

int A[NMax], B[NMax];
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
    fout << D[n][m] << "\n";
    int x = 1, y = 1;
    while(x <= n && y <= m){
        if(A[x] == B[y]){
            fout << A[x] << " ";
            x++; y++;
        } else {
            if(D[x + 1][y] > D[x][y + 1]){
                x++;
            } else {
                y++;
            }
        }
    }
    return 0;
}
