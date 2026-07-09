#include <stdio.h>

int N, M, A[1025], B[1025], D[1025][1025];
FILE *in, *out;

void getSol(int i, int j){

    if (i == 0 || j == 0)   return;

    if (A[i] == B[j]){
        getSol(i - 1, j - 1);
        fprintf(out, "%d ", A[i]);
    }else{
        if (D[i - 1][j] > D[i][j - 1])
            getSol(i -1, j);
        else
            getSol(i, j - 1);
    }

}

int main(){


    in = fopen("cmlsc.in", "r");
    out = fopen("cmlsc.out", "w");


    fscanf(in, "%d%d", &M, &N);


    for(int i = 1; i <= M; i++)
        fscanf(in, "%d", &A[i]);
    for(int i = 1; i <= N; i++)
        fscanf(in ,"%d", &B[i]);

    for(int i = 1; i <= M; i++)
        for(int j = 1; j <= N; j++){
            if (A[i] == B[j])
                D[i][j] = D[i - 1][j - 1] + 1;
            else{
                if (D[i - 1][j] > D[i][j - 1])
                    D[i][j] = D[i - 1][j];
                else
                    D[i][j] = D[i][j - 1];
            }
        }


    fprintf(out, "%d\n", D[M][N]);

    getSol(M, N);

    fclose(in);
    fclose(out);
    return 0;
}
