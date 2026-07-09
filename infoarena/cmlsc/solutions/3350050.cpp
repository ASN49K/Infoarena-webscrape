#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int M,N,vM[1024],vN[1024],a[1024][1024],k[1024],nr,MAX;

int main()
{
    fin>>M>>N;

    for(int i=1;i<=M;i++)fin>>vM[i];
    for(int i=1;i<=N;i++)fin>>vN[i];

    for(int i=1;i<=M;i++)
       for(int j=1;j<=N;j++)
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

    for(int i=0;i<nr;i++)fout<<k[i]<<" ";
    
    fin.close();
    fout.close();

    return 0;
}