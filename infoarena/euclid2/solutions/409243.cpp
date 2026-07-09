#include <stdio.h>
#define NMax 178
#define MAX 30700
struct Co{ int lin,col;};
int dlin[4]={-1,0,1,0};
int dcol[4]={0,1,0,-1};    
Co Coada[MAX];
int i,j,Nr,N,M,A[NMax][NMax],Prim,Ultim,In1,In2,Fin1,Fin2;
int Delimitare()
{
    for(i=1;i<=N;i++)
       for(j=1;j<=N;j++)
       {
        if(i==1) A[0][j]=-2;else if(i==N) A[N+1][j]=-2;
        if(j==1) A[i][0]=-2;else if(j==N) A[i][N+1]=-2;
        if(i==1 && i==j) A[0][0]=-2;
        else if(i==N && i==j) A[N+1][N+1]=-2;
        }
}
int Parcurgere()
{ 
    Co x,y;
    Prim=Ultim=0;
    x.lin=In1;
    x.col=In2;
    A[In1][In2]=1;
    Coada[Prim]=x;
    while(Prim <= Ultim && A[Fin1][Fin2]==0)
    {
     x=Coada[Prim++];
         for(i=0;i<4;++i)
         {
             y.lin=x.lin+dlin[i];
             y.col=x.col+dcol[i];
             if(A[y.lin][y.col]==0)
             {
              A[y.lin][y.col]=A[x.lin][x.col]+1;
              Coada[++Ultim]=y;
             }
         }
    }
Nr=A[Fin1][Fin2];    
}         
int main()
{int Cop1,Cop2;
    freopen("alee.in","r",stdin);
    freopen("alee.out","w",stdout);
    scanf("%d%d\n",&N,&M);
    for(i=0;i<M;i++)
       {
       scanf("%d%d\n",&Cop1,&Cop2);
       A[Cop1][Cop2]=-2;
       }
    scanf("%d%d%d%d",&In1,&In2,&Fin1,&Fin2);
    Delimitare();
    Parcurgere();
    printf("%d\n",Nr);
return 0;
}    
       