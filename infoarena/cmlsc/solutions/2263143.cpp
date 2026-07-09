#include <iostream>
#include <fstream>
#define MAX 1024

using namespace std;


int A[MAX],B[1024],mat[1024][1024],sir[1024];

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int main()
{int i,j,N,M,k=0;
    f>>M>>N;

    for(i=1;i<=M;i++)
       f>>A[i];

    for(i=1;i<=N;i++)
       f>>B[i];

    for(i=1;i<=M;i++)
       for(j=1;j<=N;j++)
         if(A[i]==B[j])
         mat[i][j]=1+mat[i-1][j-1];
       else
         mat[i][j]=max(mat[i-1][j],mat[i][j-1]);
    g<<mat[M][N]<<endl;

   i=M;
   j=N;
    while(i!=0 || j!=0)

        if(A[i]==B[j])
        {
            sir[++k]=A[i];
            i--;
            j--;
        }
      else
        if(mat[i-1][j]<mat[i][j-1])
            j--;
           else
            i--;

    for(i=k;i>=1;i--)
    g<<sir[i]<<" ";

    //Din(M,N);
    //Sir(M,N);
    return 0;
}
