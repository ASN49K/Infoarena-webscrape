#include<iostream>
#include<fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int main()
{int M,N,A[100],B[100],i,j,nr=0,K,p=0,C[100];
f>>M>>N;
for(i=1;i<=M;i++)
{f>>A[i];}
for(i=1;i<=N;i++)
{f>>B[i];}
for(i=1;i<=M;i++)
{K=0;
for(j=1;j<=N;j++)
{if(A[i]==B[j])
{K=1;}}
if(K==1)
{p++;
nr++;
C[p]=A[i];}}
g<<nr<<endl;
for(i=1;i<=nr;i++)
{g<<C[i]<<" ";}
f.close();
g.close();}