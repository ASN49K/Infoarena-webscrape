#include <iostream>
#include <fstream>
using namespace std;
int search(int x,int v[],int n)
{
 for(int i=1;i<=n;i++)
    if(x==v[i])
     return 1;
 return 0;
}
int main()
{   int N,M;
    ifstream f("cmlsc.in");
    ofstream o("cmlsc.out");
    f>>M>>N;
    int a[M+1],b[N+1],v[M+1],k=0;
    for(int i=1;i<=M;i++)
     f>>a[i];
    for(int i=1;i<=N;i++)
     f>>b[i];
    for(int i=1;i<=M;i++)
    {
     if(search(a[i],b,N))
       v[++k]=a[i];
    }
    for(int i=1;i<=k;i++)
     o<<v[i];
    return 0;
}























