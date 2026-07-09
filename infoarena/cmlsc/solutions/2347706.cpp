#include <iostream>
#include <stdio.h>

using namespace std;

unsigned short X[1025];
unsigned short Y[1025];
unsigned short M[1025][1025];
int m = 0, n = 0, k = 0;

unsigned short R[1024];

int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    scanf("%d %d", &n, &m);
    for(int i = 1; i < n + 1; i++)
        scanf("%d", &X[i]);
    for(int i = 1; i < m + 1; i++)
        scanf("%d", &Y[i]);

    for(int i =1 ; i < n + 1; i++){ M[i][0] = 0; }
    for(int j =1 ; j < m + 1; j++){ M[0][j] = 0; }

    for(int i =1 ; i < n + 1; i++){
        for(int j = 1; j < m + 1; j++){
            if(X[i] == Y[j]){
                M[i][j] = M[i-1][j-1] + 1;
                //R[k++] = X[i];
            }
            else{
                if(M[i - 1][j] < M[i][j - 1])
                    M[i][j] = M[i][j - 1];
                else
                    M[i][j] = M[i - 1][j];
            }
        }
    }

    int i =0, j=0;
    for (i = n, j = m; i; )
        if (X[i] == Y[j])
            R[k++] = X[i], --i, --j;
        else if (M[i-1][j] < M[i][j-1])
            --j;
        else
            --i;

    printf("%d\n", k);
    for(i = k - 1 ; i >= 0; i--)
        printf("%d ", R[i]);

    return 0;
}
