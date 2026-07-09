//https://www.infoarena.ro/problema/cmlsc
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll m,n, A[2000], B[2000], R[2000], R1[2000];

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

    ll maxim = 0, poz=0, m1=m, unu=1, maxim1=0;
    while(m1--){
        for(int i=unu; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(A[i] == B[j] && j>poz){
                    maxim++;
                    R[maxim] = A[i];
                    poz = j;
                }
            }
        }
        if(maxim > maxim1){
            maxim1 = maxim;
            for(int i=1; i<=maxim1; i++){
                R1[i] = R[i];
            }
        }
        maxim = 0, poz = 0;
        unu++;
    }

    cout << maxim1 << endl;
    for(int i=1; i<=maxim1; i++){
        cout << R1[i] << ' ';
    }
}