#include <iostream>
#include <stdio.h>
#include <fstream>
#define NMax 1024
#define maxim(a,b) ((a > b) ? a : b)
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int i,j,k,l,M,N,v[NMax],t[NMax],a[NMax][NMax],sir[NMax];
void afisare(int i,int j)
{
  if(a[i][j])
        if(v[i]==v[j])
        {afisare(i-1,j-1);
        g<<v[i];}
      else{ if (a[i][j]==a[i-1][j])
            afisare(i-1,j);
        else
            afisare(i,j-1);}

}
int main()
{
   f>>N;
   for(i=0;i<N;i++)
    f>>v[i];
   for(i=0;i<M;i++)
    f>>t[i];

    for(i=0;i<N;i++)
        for(j=0;j<M;j++)
        if(v[i]==t[j])
           a[i][j]==1+a[i-1][j-1];
       else
         a[i][j]=maxim(a[i-1][j],a[i][j-1]);

         g<<a[N][M]<<" ";
         afisare(N,M);






    return 0;
}
