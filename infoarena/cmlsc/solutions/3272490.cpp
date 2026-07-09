#include <bits/stdc++.h>
using namespace std;
int a, b, D[1030][1030], A[1030], B[1030], R[1030], rs;
int main(){
    ifstream cin("cmlsc.in");
    ofstream cout("cmlsc.out");
    cin >> a >> b;
    for(int i=1; i<=a; i++){
        cin >> A[i];
    }
    for(int i=1; i<=b; i++){
        cin >> B[i];
    }
    for(int i=1; i<=a; i++){
        for(int j=1; j<=b; j++){
            D[i][j] = max(max(D[i][j-1], D[i-1][j]), (D[i-1][j-1] + (A[i] == B[j])));
        }
    }
    cout << D[a][b] << endl;
    int i=a, j=b;
    while(D[i][j]){
        if(max(max(D[i][j-1], D[j][i-1]), D[j-1][i-1]) < D[i][j]){
            rs++;
            R[rs] = A[i];
            j--; i--;
        } else if(D[i][j-1] > D[i-1][j]){
            j--;
        } else {
            i--;
        }
    }

    for(int i=rs; i>=1; i--){
        cout << R[i] << ' ';
    }

}