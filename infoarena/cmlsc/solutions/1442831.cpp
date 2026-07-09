#include <fstream>

using namespace std;
ifstream fi("cmlsc.in");
ofstream fo("cmlsc.out");

int a[1025],b[1025],c[1025],d[1025][1025],i,j,m,n,y;
int main()
{
    fi>>m>>n;
    for(i=1;i<=m;i++)
      fi>>a[i];
    for(i=1;i<=n;i++)
       fi>>b[i];
    for(i=1;i<=m;i++)
      for(j=1;j<=n;j++)
         if(a[i]==b[j])
           d[i][j]=1+d[i-1][j-1];
        else
          d[i][j]=max(d[i-1][j],d[i][j-1]);
     for(i=1,j=1;i<=m,j<=n;)
          if(a[i]==b[j]){
             c[++y]=a[i];
             i++; j++;
          }
          else
            if(d[i+1][j]>d[i][j+1])
               i++;
               else
                j++;
     fo<<y<<endl;
     for(i=1;i<=y;i++)
        fo<<c[i]<<' ';
    return 0;
}
