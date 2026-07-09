#include <iostream>
#include <fstream>

using namespace std;
struct poz
{
    int val;
    int t;
} dp[1025][1025];

int main()
{
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");
    int n,m;
    f>>n>>m;
    int a[1025],b[1025];
    for(int i=1;i<=n;i++)
        f>>a[i];
    for(int i=1;i<=m;i++)
        f>>b[i];
    //poz dp[1025][1025];
    for(int i=0;i<=n;i++)
        for(int j=0;j<=m;j++)
          {
              dp[i][j].val=0;
              dp[i][j].t=0;
          }

    int x,y,z;
    int k=1;
    int sol[1025];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if(a[i]==b[j])
              {
                  x=dp[i-1][j-1].val+1;

              }
            else
                x=0;
            y=dp[i-1][j].val;
            z=dp[i][j-1].val;
            dp[i][j].val=max(max(x,y),z);
            if(dp[i][j].val==x)
                dp[i][j].t=1;
            else
            {
                if(dp[i][j].val==y)
                    dp[i][j].t=2;
                else
                    dp[i][j].t=3;
            }


        }
    int maxx=-1;
    int imax,jmax;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(dp[i][j].val>maxx)
                    {
                        maxx=dp[i][j].val;
                        imax=i;
                        jmax=j;
                    }

    g<<maxx<<endl;
    int i=imax;
    int j=jmax;
    while(dp[i][j].t!=0)
    {
        if(dp[i][j].t==1)
        {
                sol[k++]=a[i];
                i--;
                j--;
        }
        else
        {
            if(dp[i][j].t==2)
                i--;
            else
                j--;
        }


    }
    for(int i=k-1;i>=1;i--)
        g<<sol[i]<<" ";


    cout << "Hello world!" << endl;
    return 0;
}
