#include <fstream>
#include <iostream>
using namespace std;

const int MAX = 1024;

int dp[MAX][MAX], N, M, A[MAX], B[MAX], sol[MAX], size = 0;

void printResult() {
    for(int i = N, j = M; i != 0;) {
        if(A[i-1] == B[j-1]) {
            sol[size++] = A[i-1];
            i--;
            j--;
        } else { 
            if(dp[i-1][j] >= dp[i][j-1]) {
                i--;
            } else {
                j--;
            }
        }
    }
}
    
int main() {

    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);
    
    scanf("%d %d", &N, &M);
    
    for(int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    for(int i = 0; i < M; i++) {
        scanf("%d", &B[i]);
    }

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            if(A[i-1] == B[j-1]) {
                dp[i][j] = dp[i-1][j-1]+1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
     
    printf("%d\n", dp[N][M]);          
    printResult();
    for(int i = size-1; i >=0; i--) {
        printf("%d ", sol[i]);
    }

    return 0;
}
