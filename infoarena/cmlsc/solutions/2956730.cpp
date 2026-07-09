#include <fstream>

using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int a[1024],b[1024],c[1024][1024],d[10001],n,m,p;
int main()
{int i,j;
   f>>n>>m;
for(i=1;i<=n;i++)
    f>>a[i];
for(j=1;j<=m;j++)
    f>>b[j];

    for(i=1;i<=n;i++)
 for(j=1;j<=m;j++)
{if (a[i]==b[j])
c[i][j]=c[i-1][j-1]+1;
else
c[i][j]=max(c[i-1][j],c[i][j-1]);}


p=0;
   for (i=n,j=m;i>0;)
        {if(a[i]==b[j])
        {d[p++]=a[i], i--, j--;}
      else if(c[i-1][j]<c[i][j-1])
            j--;
     else
            i--;}
                g<<p<<'\n';
              for(i=p-1;i>=0;i--)
                    g<<d[i]<<" ";

    return 0;
}
