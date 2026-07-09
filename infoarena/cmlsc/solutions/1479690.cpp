#include<stdio.h>
#include<stdlib.h>

void print_matrix(int** matrix, int m, int n)
{
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
            printf("%d ",matrix[i][j]);

        printf("\n");
    }
}

int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out", "w", stdout);

    int M,N;
    scanf("%d", &M);
    scanf("%d", &N);


    //printf("    %d    ", sizeof(unsigned char));
    // sizeof(unsigned char) = 1       

    int *A,*B;
    A = (int*)malloc((M+1) * sizeof(A));
    B = (int*)malloc((N+1) * sizeof(B));

    for(int i=1;i<M+1;i++)
        scanf("%d", &A[i]);

    for(int j=1;j<N+1;j++)
        scanf("%d", &B[j]);

/*
    printf("\n");

    for(int i=1;i<N+1;i++)
        printf("%d ", A[i]);

    printf("\n");

    for(int j=1;j<N+1;j++)
        printf("%d ", B[j]);

    printf("\n");
*/
    int **mx;  // matrix

    mx = new int*[M+1];

    for(int i=0;i<M+1;i++)
        mx[i] = new int[N+1];

    for(int i=1;i<M+1;i++)
        for(int j=1;j<N+1;j++)
            {
                if(A[i] == B[j])
                    mx[i][j] = mx[i-1][j-1] + 1;
                else
                    {
                        if(mx[i][j-1] > mx[i-1][j])
                            mx[i][j] = mx[i][j-1];
                        else
                            mx[i][j] = mx[i-1][j];
                    }                
            }

    //print_matrix(mx,M+1,N+1);

    int i = M;
    int j = N;
    int idx = mx[i][j];
    int cnt = idx;
    int *rasp = new int[cnt];
    
    while(i)
    {
        if(A[i]==B[j]){
            rasp[--idx] = A[i];
            i--;
            j--;
        }
        else
            {
            if(mx[i-1][j] > mx[i][j-1])
                i--;
            else
                j--;
            }
    }        

    printf("%d\n", cnt);

    for(int i=0;i<cnt;i++)
        printf("%d ", rasp[i]);

    free(A);
    free(B);

    for (int i=0;i<M+1;i++)
        delete mx[i];
    delete[] mx;

    delete[] rasp; 
 
    return 0;
}
