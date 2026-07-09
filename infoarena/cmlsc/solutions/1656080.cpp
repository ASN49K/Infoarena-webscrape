#include <stdio.h>

#define NMax 1024

int MAX(int a, int b){

 return (a>b)? a:b ;
}
 int R[NMax][NMax],A[NMax],B[NMax],i,j,N,M,l[NMax];

int main(){
    FILE *f1=fopen("cmlsc.in", "r");
    FILE *f2=fopen("cmlsc.out","w");

    fscanf(f1,"%d %d", &M,&N);
    for (i=1;i<=M;i++)
        fscanf(f1,"%d",&A[i]);
    for (j=1;j<=N;j++)
        fscanf(f1,"%d",&B[j]);

    for (i=0;i<MAX(M,N);i++)
        l[i]=-1;

    for (i=1;i<=M;i++)
        for(j=1;j<=N;j++)
            if (A[i]==B[j])
        {
            R[i][j]=1+R[i-1][j-1];
        }
        else{
            R[i][j]=MAX(R[i-1][j],R[i][j-1]);
        }
    fprintf(f2,"%d\n",R[M][N]);
    for (i=M,j=N;i;){
        if (A[i]==B[j])
            {
                fprintf(f2,"%d ",A[i]);
                i--;
                j--;
            }
        else if (R[i-1][j]>R[i][j-1])
            i--;
        else j--;
    }
    fclose(f1);
    fclose(f2);
    return 0;
}
