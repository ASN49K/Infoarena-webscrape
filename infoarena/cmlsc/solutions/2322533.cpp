#include <iostream>
#include <fstream>

using namespace std;

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
    int dp[1025][1025];
    for(int i=0;i<=n;i++)
        for(int j=0;j<=m;j++)
            dp[i][j]=0;

    int x,y,z;
    int k=1;
    int sol[1025];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if(a[i]==b[j])
              {
                  x=dp[i-1][j-1]+1;
                  sol[k++]=a[i];
              }
            else
                x=0;
            y=dp[i-1][j];
            z=dp[i][j-1];
            dp[i][j]=max(max(x,y),z);
        }
    int maxx=-1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(dp[i][j]>maxx)
                maxx=dp[i][j];
    g<<maxx<<endl;
    for(int i=1;i<k;i++)
        g<<sol[i]<<" ";


    cout << "Hello world!" << endl;
    return 0;
}
