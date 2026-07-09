#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <deque>
using namespace std;

vector<int> x;
vector<int> y;
deque<int> d;
int c[1025][1025],n,m;

void read_input()
{
     scanf("%i %i", &n,&m);
     int i,value;
     for(i=0;i<n;i++)
     {
                     scanf("%i", &value);
                     x.push_back(value);
     }
     for(i=0;i<m;i++)
     {
                     scanf("%i", &value);
                     y.push_back(value);
     }
}


void LCS()
{
     int i,j;
     for(i=0;i<=n;i++) c[i][0]=0;
     for(j=0;j<=m;j++) c[0][j]=0;
     for(i=1;i<=n;i++)
     {
                     for(j=1;j<=m;j++)
                     {
                                  if(x[i-1]==y[j-1])
                                  {
                                                    c[i][j]=c[i-1][j-1]+1;
                                  }else
                                  {
                                       if(c[i-1][j]>=c[i][j-1]) c[i][j]=c[i-1][j];
                                       else c[i][j]=c[i][j-1];
                                  }
                     }
     }
     printf("%i\n", c[n][m]);
     int ll=n, cc=m;
     while(ll && cc)
     {
              if(ll && cc && x[ll-1]==y[cc-1]) 
              {
                    d.push_front(x[ll-1]);
                    ll--;
                    cc--;
              }
              if(ll && c[ll][cc]==c[ll-1][cc]) ll--;
              if(cc && c[ll][cc]==c[ll][cc-1]) cc--;
     }
     deque<int>::iterator it;
     for(it=d.begin();it!=d.end();++it) printf("%i ", *it);
     printf("\n");
}


int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    int i;
    read_input();
    LCS();
    scanf("%i", &i);
    return 0;
}
                 
