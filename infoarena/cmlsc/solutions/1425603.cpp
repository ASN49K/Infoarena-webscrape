#include <fstream>
#include<iostream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
unsigned N,M,a[1024],b[1024],i,j,c[1024];
void citire(unsigned N, unsigned a[1024])
{
    for(i=1;i<=N;i++)
    f>>a[i];
}
int main()
{
    f>>N>>M;
    citire(N,a);
    citire(M,b);
    unsigned x=0;
    unsigned k=0;
    for(i=1;i<=N;i++)
        for(j=1;j<=M;j++)
        if(a[i]==b[j]&& x<j) {c[++k]=a[i]; x=j;}
    g<<k;
    g<<endl;
    for(i=1;i<=k;i++)
        g<<c[i]<<" ";
    return 0;
}
