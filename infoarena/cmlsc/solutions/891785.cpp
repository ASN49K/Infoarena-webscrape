#include <stdio.h>
using namespace std;
#define MAX_N 1024
int N,M;
int V1[MAX_N+1],V2[MAX_N+1];
int T1[MAX_N+1][MAX_N+1],T2[MAX_N+1][MAX_N+1];
void Read(){
    freopen("cmlsc.in","r",stdin);
    scanf("%d %d\n",&N,&M);
    int i;
    for(i=1;i<=N;i++){
        scanf("%d ",&V1[i]);
    }
    for(i=1;i<=M;i++){
        scanf("%d ",&V2[i]);
    }
    fclose(stdin);
}
void PD()
{
    int i,j,n=N,m=M;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(V1[i]==V2[j])
            {
                T1[i][j]=T1[i-1][j-1]+1;
                T2[i][j]=0;
            }
            else
            {
                if(T1[i-1][j]>T1[i][j-1]){
                    T1[i][j]=T1[i-1][j];
                    T2[i][j]=1;
                }
                else{
                    T1[i][j]=T1[i][j-1];
                    T2[i][j]=-1;
                }
            }
        }
    }
}
void write(int t[MAX_N+1][MAX_N+1])
{
    int i,j;
    for(i=1;i<=N;i++)
    {
        for(j=1;j<=M;j++)
        {
            printf("%d ",t[i][j]);
        }
        printf("\n");
    }
}

void Write(int i,int j){
    if(i<1||j<1)
        return;
    if(T2[i][j]==0){
        Write(i-1,j-1);
        printf("%d ",V1[i]);
    }
    else
        if(T2[i][j]==1)
            Write(i-1,j);
        else
            Write(i,j-1);
}
int main()
{
    Read();
    PD();
    freopen("cmlsc.out","w",stdout);
    Write(N,M);
    fclose(stdout);
    return 0;
}
