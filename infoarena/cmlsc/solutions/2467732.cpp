#include <iostream>
#include <fstream>


using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n,m,a[1024],b[1024],i,j,v[1024][1024],nn,l[1024];
int main()
{

    f>>n>>m;
    for(i=1;i<=n;i++)
    {
      f>>a[i];
    }
    for(i=1;i<=m;i++)
    {
      f>>b[i];

        for(j=1;j<=n;j++)
    {
        if(b[i]==a[j])v[j][i]=v[j-1][i-1]+1;
        else v[j][i]=max(v[j-1][i],v[j][i-1]);
    }

    }
   g<<v[n][m]<<endl;


   i=n;
   j=m;
   while(v[i][j]!=0)
   {
    while(v[i][j]==v[i][j-1])j--;
    while(v[i][j]==v[i-1][j])i--;
    l[++nn]=a[i];
    i--;
    j--;
    }

   for(i=nn;i>0;i--)g<<l[i]<<" ";



}
