#include <iostream>
#include <fstream>
#include <climits>

#define N 1025

using namespace std;
int A[N], B[N], c[N][N], res[N];

int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);
    int n, m, index = 0;

    scanf("%i%i", &n, &m);

    for(int i = 1; i <= n; ++i){
        scanf("%i", &A[i]);
    }
    for(int i = 1; i <= m; ++i){
        scanf("%i", &B[i]);
    }

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            c[i][j] = ((A[i] == B[j])? c[i-1][j-1]+1:max(c[i][j-1], c[i-1][j]));
        }
    }

    while(n){
        if(A[n] == B[m]){
            res[index++] = A[n--];
            m--;
        }
        else{
            (c[n-1][m] < c[n][m-1])? m--:n--;
        }
    }

    printf("%i\n", index);
    for(int i = index-1; i >= 0; --i){
        printf("%i ", res[i]);
    }

    return 0;
}
