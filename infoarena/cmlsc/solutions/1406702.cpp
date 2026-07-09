#include <fstream>
#include <iostream>
using namespace std;
int a[1024],b[1024],c[1024],d[1024];
int n,m,mas,p,q;

void verif(int x,int y)
{
    int k=x,l=y,ls=x,ld;
    while(a[k]==b[l] && k<=n && l<=m)
    {
      ld=k;
      if(ld-ls+1>mas){mas=ld-ls+1;   p=x; q=ld;}
      k++;
      l++;
    }

}

int main()
{
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");
    int i,j;
    f >> n >> m;
    for(i=1;i<=n;i++) f >>a[i];
    for(i=1;i<=m;i++) f >>b[i];

    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++) verif(i,j);
    g << mas << endl;
    for(i=p;i<=q;i++) g << a[i] << " ";

}
