#include<iostream>
#include<fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int main()
{int M,N,A[256],B[256],i,j,MAX=0,K,p=0,C[100];
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
MAX++;
C[p]=A[i];}}
g<<MAX<<endl;
for(i=1;i<=MAX;i++)
{g<<C[i]<<" ";}
f.close();
g.close();}