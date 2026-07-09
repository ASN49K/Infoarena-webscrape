#include <stdio.h>
#include <cmath>
using namespace std;
FILE *f,*g;
int D[1027][1027],N,M;
int A[1027],B[1027];
void Read()
{
    int i;
    fscanf(f,"%d %d",&N,&M);
    for(i=1;i<=N;i++)fscanf(f,"%d",&A[i]);
    for(i=1;i<=M;i++)fscanf(f,"%d",&B[i]);
}
int MAX(int A,int B)
{
    if(A>B)return A;
    return B;
}
void Dynamic()
{
    int i,j;
    for(i=1;i<=N;i++)
        for(j=1;j<=M;j++)
            if(A[i]==B[j])D[i][j]=D[i-1][j-1]+1;
            else
                D[i][j]=MAX(D[i-1][j],D[i][j-1]);
    fprintf(g,"%d\n",D[N][M]);
}
void Displaying(int i,int j)
{
   if(i && j)
   {
      if(A[i]==B[j])
      {
         Displaying(i-1,j-1);
         fprintf(g,"%d ",A[i]);
      }
      else
        if(D[i-1][j]>D[i][j-1])Displaying(i-1,j);
        else
            Displaying(i,j-1);
   }
}
int main()
{
    f=fopen("cmlsc.in","r");g=fopen("cmlsc.in","w");
    Read();
    Dynamic();
    Displaying(N,M);
    fclose(f),fclose(g);
    return 0;
}
