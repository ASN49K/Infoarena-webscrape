#include <iostream>
#include <fstream>
using namespace std;
ifstream f("cmlsc.txt");
ofstream g("cmlsc.out");
short int n,m;
short int s[1025],x[1025],v[1025];
short int c[1025][1025];
int main()
{
      f>>n>>m;
      short int i,j=0;
      for(i=1;i<=n;++i)
        f>>s[i];
         for(j=1;j<=m;++j)
           f>>x[j];
         f.close();
             for(i=1;i<=n;++i)
               for(j=1;j<=m;++j)
                if (s[i]==x[j]) c[i][j]=1+c[i-1][j-1];
                 else
                 {
                   short int max=c[i-1][j];
                   if (max<c[i][j-1]) max=c[i][j-1];
                   c[i][j]=max;
                 }
           i=n;
           j=m;
           while (c[i][j]!=0)
           {
               if (s[i]==x[j])
               {
                   v[c[i][j]]=s[i];
                   --i;
                   --j;
               }
               else
               {
                   if (c[i-1][j]>c[i][j-1]) --i;
                   else --j;
               }
           }
           g<<c[n][m]<<"\n";
           for(i=1;i<=c[n][m];++i)
             g<<v[i]<<" ";
             g.close();
    return 0;
}
