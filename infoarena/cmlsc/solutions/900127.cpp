#include <stdio.h>
#include <algorithm>
using namespace std;
short a[1050], b[1050], sir[1050];
short mat[1050][1050];
short N, M, i, j, k;
int main(){
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    scanf("%d%d", &N, &M);
    for(i = 1; i <= N; i++){
        scanf("%d", &a[i]);
    }
    for(i = 1; i <= M; i++){
        scanf("%d", &b[i]);
    }
    for(i = 1; i <= N; i++){
        for(j = 1; j <= M; j++){
            if(a[i] == b[j]){
                mat[i][j] = mat[i-1][j-1] + 1;
            }else{
                mat[i][j] = max(mat[i-1][j], mat[i][j-1]);
            }
        }
    }
    printf("%d\n", mat[N][M]);
    for(i = N, j = M; i;){
        if(a[i] == b[j]){
            sir[++k] = a[i]; --i; --j;
        }else if(mat[i-1][j] < mat[i][j - 1]){
            j--;
        }else{
            i--;
        }
    }
    for(i = k; i >= 1; i--){
        printf("%d ", sir[i]);
    }
}
