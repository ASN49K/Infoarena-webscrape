#include <bits/stdc++.h>
using namespace std;
int m, n, A[1050], B[1050], D[1030][1030], r , R[1040];
int main(){
    ifstream cin("cmlsc.in");
    ofstream cout("cmlsc.out");
    cin >> m >> n;
    for(int i=1; i<=m; i++){
        cin >> A[i];
    }

    for(int i=1; i<=n; i++){
        cin >> B[i];
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            D[j][i] = max({D[j][i-1], D[j-1][i], (D[j-1][i-1] + (B[i] == A[j]))});
            // cout << D[j][i] << ' ';
        }
    }

    cout << D[m][n] << endl;
    int rs = D[m][n];
    int i = n, j = m;
    while(rs!=0){
        if(D[j-1][i-1] < D[j][i]){
            r++;
            R[r] = A[j];
            j--; i--;
            rs = D[j][i-1];
        } else {
            j--;
            rs = D[j][i];
        }
    }

    for(int i=r; i>=1; i--){
        cout << R[i] << ' ';
    }
}