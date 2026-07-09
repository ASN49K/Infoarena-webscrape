#include <fstream>

using namespace std;
ifstream fi("cmlsc.in");
ofstream fo("cmlsc.out");

int a[2000],b[1025],c[1025],d[1025][1025],i,j,m,n,y;
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
     for(i=m,j=n;i>=1 && j>=1;)
          if(a[i]==b[j]){
             c[++y]=a[i];
             i--; j--;
          }
          else
            if(d[i-1][j]>d[i][j-1])
               i--;
               else
                j--;
     fo<<d[m][n]<<endl;
     for(i=y;i>=1;i--)
        fo<<c[i]<<' ';
        fo<<endl;
//     for(i=1;i<=m;i++){
//      for(j=1;j<=n;j++)
//        fo<<d[i][j]<<' ';
//      fo<<endl;
//     }
    return 0;
}
