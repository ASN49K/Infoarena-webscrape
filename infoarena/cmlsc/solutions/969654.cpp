#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int n,m;
short v[1100],u[1100];
short a[1100][1100];

int main()
{


    f>>n>>m;

    for(int i=1;i<=n;i++)
        f>>v[i];
    for(int j=1;j<=m;j++)
        f>>u[j];

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(v[i]==u[j])
                a[i][j]=a[i-1][j-1]+1;
            else
                a[i][j]=max(a[i-1][j],a[i][j-1]);
    g<<a[n][m]<<'\n';

    vector<int> sol;
    for(int i=m;i>0;i--)
        if(a[n][i]<a[n][i+1])
            sol.push_back(u[i+1]);
    for(int i=sol.size()-1;i>=0;i--)
        g<<sol[i]<<" ";

    return 0;
}
