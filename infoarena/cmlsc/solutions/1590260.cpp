#include<iostream>
#include<fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int main()
{int M,N,A[2000],B[2000],i,j,p,K,max=0;
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
cout<<"K="<<K<<endl;
if(K==0)
{A[i]=98765;}}
for(i=1;i<=M;i++)
{if(A[i]!=98765)
{max++;}}
g<<max<<endl;
for(i=1;i<=M;i++)
{if(A[i]!=98765)
{g<<A[i]<<" ";}}

f.close();
g.close();}