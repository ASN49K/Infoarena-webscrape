#include <iostream>
#include<fstream.h>

using namespace std;

int n,m,a[1026],b[1026],sc[1026],v=0;

void verificare(int n, int m, int a[],int b[])
{
    ofstream g("cmlsc.out");
    int p1=0,p2=0;
    for(int i=p1;i<n;i++)
         for(int j=p2;j<m;j++)
              if(a[p1]==b[p2])
              {
                  sc[v]=a[p1];
                  v++;
                  p2=j+1;
              }
              else
                p1++;
    g<<v<<endl;
    for(int i=0;i<v;i++)
        g<<sc[i]<<" ";
}
int main()
{

    ifstream f("cmlsc.in");
    f>>n>>m;

    int sc[n*m];

    for(int i=0;i<n;i++)
       f>>a[i];
    for(int i=0;i<m;i++)
       f>>b[i];
    if(n>=m)
             verificare(n,m,a,b);
    else
             verificare(m,n,b,a);

    return 0;
}
