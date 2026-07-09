#include <stdio.h>

#define NMax 1024

int MAX(int a, int b){

 return (a>b)? a:b ;
}
 int R[NMax][NMax];

int main(){
    int N,M,i,j,A[NMax],B[NMax];
    FILE *f1=fopen("cmlsc.in", "r");
    FILE *f2=fopen("cmlsc.out","w");

    fscanf(f1,"%d %d", &M,&N);
    for (i=1;i<=M;i++)
        fscanf(f1,"%d",&A[i]);
    for (j=1;j<=N;j++)
        fscanf(f1,"%d",&B[j]);


    int l[MAX(M,N)];
    for (i=0;i<M;i++)
        for(j=0;j<N;j++)
           R[i][j]=0;
    for (i=0;i<MAX(M,N);i++)
        l[i]=-1;
    int cnt=0;
    for (i=1;i<=M;i++)
        for(j=1;j<=N;j++)
            if (A[i]==B[j])
        {
            R[i][j]=1+R[i-1][j-1];
            l[cnt]=A[i];
            cnt++;
        }
        else{
            R[i][j]=MAX(R[i-1][j],R[i][j-1]);
        }
    fprintf(f2,"%d\n",R[M][N]);
    for (i=0;i<MAX(M,N);i++){
        if (l[i]!=-1) fprintf(f2,"%d ",l[i]);
        else break;
    }
    fclose(f1);
    fclose(f2);
    return 0;
}
