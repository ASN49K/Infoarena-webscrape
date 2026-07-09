#include <iostream>
#include <fstream>
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int i,j,k=0,a[10001][10001],b[10001[10001],l[1001][1001],c[10001];
int main()
{
   in>>n>>m;
   for(i=1;i<=n;i++)
   in>>a[i];
   for(i=1;i<=m;i++)
   in>>b[i];
   for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
       if(a[i]==b[j])
       l[i][j]=l[i-1][j-1]+1;
       else
       l[i][j]=max(l[i-1][j],l[i][j-1]);
       i=n;
       j=m;
       while(i>0 && j>0)
       if(a[i]==b[j])
       {k++;
        c[k]=a[i];
        i--;
        j--;}
        else
        if(l[i][j-1]>l[i-1][j])
        j--;
        else
        i--;
        out<<l[n][m]<<"\n";
        for(i=1;i<=k;i++)
        out<<c[i]<<" ";
        return 0;

}
