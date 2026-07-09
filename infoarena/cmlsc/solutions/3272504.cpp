#include <bits/stdc++.h>
using namespace std;
int a, b, A[1050], B[1050], D[1030][1030], r , R[1040];
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
            D[j][i] = max(max(D[j][i-1], D[j-1][i]), (D[j-1][i-1] + (A[i] == B[j])));
            cout << D[j][i] << ' ';
        }
        cout << '\n';
    }

    cout << D[b][a] << endl;
    int i = a, j = b;
    while(D[j][i]){
        if(max(max(D[j-1][i], D[j][i-1]), D[j-1][i-1]) < D[j][i]){
            r++;
            R[r] = B[j];
            j--; i--;
        } else if(D[j-1][i] > D[j][i-1]){
            j--;
        } else {
            i--;
        }
    }

    for(int i=r; i>=1; i--){
        cout << R[i] << ' ';
    }
}