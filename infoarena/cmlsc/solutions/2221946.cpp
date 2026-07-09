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
int check(int x, int y, int v[], int n)
{
 for(int i=1;i<=n;i++)
 {
    if(v[i]==y)
     return 0;
    if(v[i]==x)
     return 1;
 }
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
      if(k==0)
       v[++k]=a[i];
      else
       if(check(a[i],v[k],b,N))
        v[++k]=a[i];
    }
    for(int i=1;i<=k;i++)
     o<<v[i];
    return 0;
}























