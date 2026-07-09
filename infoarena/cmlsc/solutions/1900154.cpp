#include <cstdio>
#include <algorithm>
using namespace std;

int M, N, input1[1025], input2[1025];
int sol[1025][1025], lcs[1025];

int main(){

    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    scanf("%d %d", &M, &N);

    for(int i = 1; i <= M; i++){
        scanf("%d", &input1[i]);
    }
    for(int j = 1; j <= N; j++){
        scanf("%d", &input2[j]);
    }
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            if(input1[j] == input2[i]){
                sol[i][j] = 1 + sol[i-1][j-1];
            }else{
                sol[i][j] = max(sol[i-1][j], sol[i][j-1]);
            }
        }
    }
    int length = sol[N][M];
    int k = sol[N][M];
    int i = N;
    int j = M;
    printf("%d\n", length);

    while(1){
        if(input1[j] == input2[i]){
            lcs[k--] = input1[j];
            i--; j--;
        }else if(sol[i][j] == sol[i][j-1]){
            j--;
        }else i--;

        if(k == 0) break;
    }

    for(int i = 1; i <= length; i++){
        printf("%d ", lcs[i]);
    }

    return 0;
}
