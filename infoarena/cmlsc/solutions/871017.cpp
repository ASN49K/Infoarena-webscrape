#include <fstream>
//#define DEBUG
using namespace std;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
int i, j, n, m, a[1030], b[1030], d[1030][1030], sol[1030];
inline int MAX(int x, int y)
{
       if(x>y)
          return x;
       else return y;
       }
int main()
{
    cin>>n>>m;
    for(i=1;i<=n;i++) 
                      cin>>a[i];
    for(j=1;j<=m;j++)
                      cin>>b[j];
    for(i=1;i<=n;i++)
                     for(j=1;j<=m;j++)
                                      if(a[i]==b[j])
                                          d[i][j]=d[i-1][j-1]+1;
                                      else d[i][j]=MAX(d[i-1][j], d[i][j-1]);
  #ifdef DEBUG
    for(i=1;i<=n;i++)
                    { for(j=1;j<=m;j++)
                                      cout<<d[i][j]<<" ";
                     cout<<"\n";}
  #endif
    cout<<d[n][m]<<"\n";
    int best=d[n][m];
    i=n;
    j=m;
    while(i>=1 && j>=1)
    {
               if(a[i]==b[j])
                  { sol[best]=a[i]; best--;
                    i--;
                    j--;   }
               else if(d[i-1][j]>d[i][j-1])
                         i--;
               else j--;
               }
    for(i=1;i<=d[n][m];i++)
         cout<<sol[i]<<" ";           
                       
    return 0;
}
