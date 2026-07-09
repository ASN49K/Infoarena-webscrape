#include <stdio.h>
#include <stdlib.h>

int lengthLCS(int* stString, int* ndString, int M, int N);
int max(int a,int b);


int main()
{
    int M,N;
    int i,j;
    int* stString;
    int* ndString;

    FILE* in = fopen("cmlsc.in","r");
    FILE* out = fopen("cmlsc.out","w");

    fscanf(in,"%d",&M);
    fscanf(in,"%d",&N);

    stString = (int*)malloc(M*sizeof(int));
    ndString = (int*)malloc(N*sizeof(int));

    for(i=0; i<M; i++)
        fscanf(in,"%d",stString + i);
    for(j=0; j<N; j++)
        fscanf(in,"%d",ndString + j);

    fprintf(out,"%d\n",lengthLCS(stString,ndString,M,N));

    free(stString);
    free(ndString);

    fclose(in);
    fclose(out);
}

int lengthLCS(int* stString,int* ndString,int M,int N)
{
    int i,j;

    /* Allocating memory.. */
    int** lengthRoot;
    lengthRoot = (int**)malloc((M+1)*sizeof(int*));
    for(i=0; i<M+1; i++)
        lengthRoot[i] = (int*)malloc((N+1)*sizeof(int));

    for(i=0;i<M+1;i++)
        lengthRoot[0][i]=0;
    for(i=0;i<N+1;i++)
        lengthRoot[i][0]=0;


    for(i=1;i<M+1;i++)
        for(j=1;j<N+1;j++)
        {
            if(stString[i-1]==ndString[j-1]) lengthRoot[i][j] = 1+lengthRoot[i-1][j-1];
            else lengthRoot[i][j] = max(lengthRoot[i-1][j],lengthRoot[i][j-1]);
        }

    return lengthRoot[M][N];
}

int max(int a, int b)
{
    if(a > b) return a;
    else return b;
}
