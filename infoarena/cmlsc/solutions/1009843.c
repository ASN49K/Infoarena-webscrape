#include <stdio.h>
#include <stdlib.h>

int in1[1025], in2[1025];
int matrix[1025][1025];

int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    int m,n;

    scanf("%d %d", &m, &n);

    for (int i=1; i<=m; i++){
        scanf("%d", &in1[i]);
    }

    for (int i=1; i<=n; i++){
        scanf("%d", &in2[i]);
    }

    //actual solution
    for (int i=1; i<=m; i++){
        for (int j=1; j<=n; j++){
            if (in1[i] == in2[j]) {
                matrix[i][j] = matrix[i-1][j-1] + 1;
            } else {
                if (matrix[i][j-1] > matrix[i-1][j]){
                    matrix[i][j] = matrix[i][j-1];
                } else {
                    matrix[i][j] = matrix[i-1][j];
                }
            }
        }

    }

    int maxLength = matrix[m][n];

    printf("%d\n", maxLength);

    int currentI = m;
    int currentJ = n;
    int currentPosition = maxLength;

    int solution[1025];

    while (currentPosition > 0){
        if (in1[currentI] == in2[currentJ]){
            solution[currentPosition--] = in1[currentI];
            currentI--;
            currentJ--;
        } else if (matrix[currentI][currentJ-1] > matrix[currentI-1][currentJ]) {
            currentJ--;
        } else {
            currentI--;
        }
    }

    for (int i=1; i<=maxLength; i++){
        printf("%d ", solution[i]);
    }

    return 0;
}
