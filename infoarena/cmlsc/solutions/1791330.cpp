#include <iostream>
#include <fstream>

using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int main()
{
   int a[1050],b[1050],n,m,i,j,dmax[1050][1050],rez[1050];
   f>>n>>m;
   for(i=1;i<=n;i++) f>>a[i];
   for(j=1;j<=m;j++) f>>b[j];
   for(i=0;i<=n;i++)
    dmax[0][i]=0;
   for(i=0;i<=m;i++)
    dmax[0][i]=0;
   for(i=1;i<=n;i++)
   {
       for(j=1;j<=m;j++)
       {
           if(a[i]==b[j])
            dmax[i][j]=dmax[i-1][j-1]+1;
           else
            dmax[i][j]=dmax[i-1][j-1];
           dmax[i][j]=max(dmax[i][j],max(dmax[i-1][j],dmax[i][j-1]));

       }
   }
   g<<dmax[n][m]<<'\n';

   i=n;
   j=m;
   int rezl=0;
   while(i>=0 && j>=0)
   {
       if(a[i]==b[j])
       {
        rez[rezl++]=a[i];
        i--;
        j--;
       }
       else
            if(dmax[i-1][j]> dmax[i][j-1])
            {
                i--;
            }
            else
                j--;
   }
   for(i=rezl-1;i>=0;i--)
    g<<rez[i]<<" ";
    return 0;
}
