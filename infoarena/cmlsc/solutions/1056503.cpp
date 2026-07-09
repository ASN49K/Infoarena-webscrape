#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
vector <int>s;
int n,m,a[1025],b[1025],l[1025][1025],i,j;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int main()
{
    f>>n>>m;
    for(i=1;i<=n;i++)
    f>>a[i];
    for(j=1;j<=m;j++)
     f>>b[j];
     for(i=1;i<=n;i++)
      for(j=1;j<=m;j++)
      {
          if(a[i]==b[j])
            l[i][j]=1+l[i-1][j-1];
        else
            l[i][j]=max(l[i-1][j],l[i][j-1]);
      }
    g<<l[n][m]<<'\n';
    for(i=n,j=m;l[i][j];)
    {
        if(a[i]==b[j])
        {
            s.push_back(a[i]);
            i--;
            j--;

        }
         else
         if(l[i][j]==l[i-1][j])
            i--;
            else
            j--;

    }
    for(;s.size();s.pop_back())
        g<<s.back()<<' ';

    return 0;
}
