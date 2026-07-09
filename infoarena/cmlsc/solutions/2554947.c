#include <stdio.h>
#include <stdlib.h>

#define MAXM(a,b) ((a) > (b)? (a) : (b))

void read(FILE *fin, int m, int n, int a[], int b[])
{
    for(int i = 0; i < m; i++)
    {
        fscanf(fin,"%d ", &a[i]);
        /*if(a[i] > 256)
        {
            printf("Invalid input!");
            exit(1);
        }*/
    }

    for(int i = 0; i < n; i++)
    {
        fscanf(fin, "%d ", &b[i]);
       /* if(b[i] > 256)
        {
            printf("Invalid input!");
            exit(1);
        }*/
    }
}

void find(int m, int n, int a[], int b[], FILE *fout)
{
    int A[MAXM(m,n)][MAXM(m,n)], ai = 0, bi = 0, aistart = 0, bistart = 0, col = 0, row = 0, colm = 0;
    while(aistart != m)
    {
        for(ai = aistart; ai < m; ai++)
        {
            for(bi = bistart; bi < n; bi++)
            {
                if(a[ai] == b[bi])
                {
                    A[row][col++] = a[ai];
                    bistart = bi + 1;
                    break;
                }
            }
        }
        if(col > colm)
        {
            colm = col;
            for(int i = 0; i < col; i++)
            {
                A[0][i] = A[row][i];
            }
            A[0][col] = -1;
        }
        A[row][col] = -1;
        row++;
        col = 0;
        bistart = 0;
        aistart++;
    }

    fprintf(fout, "%d\n",colm);
    //printf("%d\n",colm);
    for(int i = 0; i < colm; i++)
    {
        fprintf(fout, "%d ", A[0][i]);
        //printf("%d ",A[0][i]);
    }
}

int main()
{
    FILE *fin = fopen("cmlsc.in","r"), *fout = fopen("cmlsc.out", "w");
    int M, N;
    fscanf(fin, "%d %d", &M, &N);

    /*if(M < 1 || M > 256 || N < 1 || N > 256)
    {
        printf("Invalid input!");
        exit(1);
    }*/

    int A[M], B[N];

    read(fin, M, N, A, B);
    find(M, N, A, B, fout);

    fclose(fin);
    fclose(fout);
    return 0;
}
