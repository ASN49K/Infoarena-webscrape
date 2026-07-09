#include <fstream>
#include <vector>

using namespace std;
int a[1025],b[1025];
int sol[1025][1025];
vector<int>afis;
int main()
{
    ifstream cin("cmlsc.in");
    ofstream cout("cmlsc.out");
    int n,m;
    cin>>n>>m;
    for(int i=1; i<=n; i++)
        cin>>a[i];
    for(int i=1; i<=m; i++)
        cin>>b[i];
    for(int i=1; i<=m; i++)
    {
        if(a[1]==b[i])
            sol[1][i]=1;
        else
            sol[1][i]=sol[1][i-1];
    }
    for(int i=1; i<=n; i++)
    {
        if(a[i]==b[1])
            sol[i][1]=1;
        else
            sol[i][1]=sol[i-1][1];
    }
    for(int i=2; i<=n; i++)
    {
        for(int j=2; j<=m; j++)
        {
            if(a[i]==b[j])
                sol[i][j]=sol[i-1][j-1]+1;
            else
                sol[i][j]=max(sol[i-1][j],sol[i][j-1]);
        }
    }
    cout<<sol[n][m]<<'\n';
    while(n&&m)
    {
        if(a[n]==b[m])
            afis.push_back(a[n]),n--;
        else
        {
            if(sol[n][m-1]>sol[n-1][m])
                m--;
            else
                n--;
        }
    }
    for(int i=afis.size()-1; i>=0; i--)
        cout<<afis[i]<<" ";
    return 0;
}
