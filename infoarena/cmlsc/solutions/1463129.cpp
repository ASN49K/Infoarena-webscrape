#include <iostream>
#include <stdio.h>
#define NMax 1025
using namespace std;
int N,M,k;
int X[NMax],Y[NMax],D[NMax][NMax],sol[NMax];

void Read()
{
    freopen("cmlsc.in","r",stdin);
    scanf("%d%d",&N,&M);
    for(int i=1;i<=N;i++)
        scanf("%d",&X[i]);

    for(int i=1;i<=M;i++)
        scanf("%d",&Y[i]);
}

void Dinamic()
{
    for(int i=0;i<=N;i++)
    for(int j=0;j<=M;j++)
         if((i == 0) || (j == 0))
                D[i][j] = 0;
    else
    {if(X[i]==Y[j])
    {
        D[i][j]=D[i-1][j-1]+1;
    }
    else
    {
        D[i][j]=max(D[i][j-1],D[i-1][j]);
    }}
}

void Solve()
{
    int i=N;
    int j=M;
    k=0;
    while((i>0) &&(j>0))
    {
        if(X[i]==Y[j])
        {
            sol[k]=X[i];
            k++;
            i--;
            j--;
        }
        else if(D[i][j-1]>D[i-1][j])
        {
            j--;
        }
        else
        {
            i--;
        }
    }

     freopen("cmlsc.out","w",stdout);
    printf("%d\n",D[N][M]);
    for(int i=k-1;i>=0;i--)
        printf("%d ",sol[i]);
}

/*void Write()
{
    freopen("cmlsc.out","w",stdout);
    printf("%d\n",D[N][M]);
    for(int i=k-1;i>=0;i--)
        printf("%d ",sol[i]);
}*/

int main()
{
    Read();
    Dinamic();
    Solve();
    //Write();
}
