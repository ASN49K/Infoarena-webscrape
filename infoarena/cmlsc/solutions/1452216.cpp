#include <iostream>
#include <stdio.h>
#include <fstream>
#define NMAX 1024
#define maxim(a, b) ((a > b) ? a : b)

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int A[NMAX],B[NMAX],i,j,N,M;

void Citire()
{   fin>>M>>N;
    for(i=1;i<=M;++i)
        fin>>A[i];
    for(i=1;i<=N;++i)
        fin>>B[i];
}
int dist[NMAX][NMAX];

void ConstruireMatrice()
{
    for(i=1;i<=M;++i)
      for(j=1;j<=N;++j)
        if(A[i]==B[j])
            dist[i][j]=dist[i-1][j-1]+1;
        else
            dist[i][j]=maxim(dist[i][j-1],dist[i-1][j]);

}

void AfisareSol()
{   int k=0,sol[NMAX];
    i=M,j=N;
    while(i>=0 && j>=0)
       {
           if(A[i]==B[j])
               sol[++k]=A[i],--i,--j;
           else
              if(dist[i-1][j]<dist[i][j-1])
                     --j;
              else
                     --i;
       }
     fout<<k;
     fout<<"\n";
     for(i=k;i>=2;--i)
        fout<<sol[i]<<" ";
     fout<<sol[1];
}

int main()
{
   Citire();
   ConstruireMatrice();
   AfisareSol();
   return 0;
}
