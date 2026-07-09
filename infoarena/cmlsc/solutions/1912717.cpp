#include <iostream>
#include <fstream>
#include <stdio.h>
#define n 1025
using namespace std;
int A[1025]={0}, B[1025]={0}, M[n][n]={0},C[1024]={0},nrc=0;
int x,y, i, j, lsc, var1, p;


int main()
{ ifstream fin("cmlsc.in");    ofstream fout("cmlsc.out");
   fin>>x>>y;
   for(i=1;i<=x;i++)
   {fin>>p; M[i][0]=0; A[i]=p;}

   for(i=1;i<=y;i++)
    {fin>>p;   M[0][i]=0;   B[i]=p;}

   for(i=1;i<=x;i++)
    {
    for(j=1;j<=y;j++)
   {
     if(A[i]==B[j])
       {
          M[i][j]=M[i-1][j-1]+1;
       }
     else
     {
       M[i][j]=max(M[i-1][j],M[i][j-1]);
     }
   }
   }

    for (i = x, j = y; i; )
        if (A[i] == B[j])
            C[++nrc] = A[i], --i, --j;
        else if (M[i-1][j] < M[i][j-1])
            --j;
        else
            --i;

   fout<<nrc<<"\n";
    for (i = nrc; i; --i)
         fout<<C[i]<<" ";

    return 0;
}
