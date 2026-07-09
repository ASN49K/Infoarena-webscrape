#include <iostream>
#include <fstream>
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int main()
{  int i,j,n,m,k=0,a[2000],b[2000],l[2000][2000],c[2000];
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
       i=n;  j=m;
       while(i>0 && j>0)
       if(a[i]==b[j])
       {k++;
        c[k]=a[i];
        i--;
        j--;
        }
        else
        {if(l[i][j-1]>l[i-1][j])
        j--;
        else
        i--;
        }
        out<<l[n][m]<<endl;
        for(i=1;i<=k;i++)
        out<<c[i]<<" ";
        return 0;
}
