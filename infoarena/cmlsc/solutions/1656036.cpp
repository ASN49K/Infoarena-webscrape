#include <stdio.h>

#define NMax 1024

int MAX(int a, int b){

 return (a>b)? a:b ;
}

int main(){
    int N,M,i,j,A[NMax],B[NMax];
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out","w", stdout);

    scanf("%d %d", &M,&N);
    for (i=1;i<=M;i++)
        scanf("%d",&A[i]);
    for (j=1;j<=N;j++)
        scanf("%d",&B[j]);

    int R[M][N];
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
    printf("%d\n",R[M][N]);
    for (i=0;i<MAX(M,N);i++){
        if (l[i]!=-1) printf("%d ",l[i]);
        else break;
    }

}
