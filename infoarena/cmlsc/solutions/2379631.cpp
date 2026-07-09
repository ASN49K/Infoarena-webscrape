#include <bits/stdc++.h>
using namespace std;
#define NMAX 1024
int X[NMAX], Y[NMAX], D[NMAX][NMAX], OUT[NMAX];
int main(){
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i<=n; i++) scanf("%d", &X[i]);
    for(int i = 1; i<=m; i++) scanf("%d", &Y[i]);
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            if(X[i]==Y[j]){
                D[i][j] = D[i-1][j-1]+1;
            }
            else D[i][j] = max(D[i][j-1], D[i-1][j]);
        }
    }
    int len = 0;
    for(int i = n, j = m; i; ){
        if(X[i]==Y[j]){
            OUT[++len] = X[i];
            i--;
            j--;
        }
        else if(D[i-1][j]<D[i][j-1]) j--;
        else i--;
    }
    printf("%d\n", len);
    for(int i = len; i>=1; i--) printf("%d ",OUT[i]);
}
