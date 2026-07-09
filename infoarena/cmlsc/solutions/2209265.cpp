#include <iostream>
#include <fstream>
#include <stdio.h>
#define maxim(a, b) ((a > b) ? a : b)
using namespace std;
int D[1024][1024];
int main()
{
    int A[1024],B[1024], sir[1024],i,j,n,m,k;
   ifstream f("cmlsc.in");
   ofstream g("cmlsc.out");

   f>>m>>n;
   for(i=1;i<=m;i++)
      f>>A[i];
    for(j=1;j<=n;j++)
       f>>B[j];


 for(i=1;i<=m;i++)
    for(j=1;j<=n;j++)
       {if(A[i]== B[j])
          D[i][j]= D[i-1][j-1] + 1;
       else D[i][j]= max(D[i-1][j],D[i][j-1]);
       }
 i=m;
 j=n;
 k=0;
 while(i)
 {
     if(D[i][j]==D[i-1][j])
        i--;
     else
     {if (D[i][j]==D[i][j-1])
                j--;
     else if(D[i][j]==D[i-1][j-1]+1)
           {
              sir[++k]=A[i];
              i--;
               j--;
           }
     }

 }
for(i=1;i<=m;i++)
    {for(j=1;j<=n;j++)
  /*cout<<D[i][j]<<" ";
  cout<<endl;}
  cout<<endl; */
   for(i=k;i>=1;i--)
    g<<sir[i]<<" ";

}
