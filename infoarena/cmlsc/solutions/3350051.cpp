#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

long long M,N,vM[1026],vN[1026],a[1026][1026],k[1026],nr,MAX;

int main()
{
    fin>>M>>N;

    for(long long i=1;i<=M;i++)fin>>vM[i];
    for(long long i=1;i<=N;i++)fin>>vN[i];

    for(long long i=1;i<=M;i++)
       for(long long j=1;j<=N;j++)
       {
          if(vM[i]==vN[j])
          {
            a[i][j]=a[i-1][j-1]+1;
            k[nr++]=vM[i];
          }
          else a[i][j] = max(a[i-1][j],a[i][j-1]);
       }
       
    MAX=a[M][N];

    fout<<MAX<<'\n';

    for(long long i=0;i<nr;i++)fout<<k[i]<<" ";
    
    fin.close();
    fout.close();

    return 0;
}