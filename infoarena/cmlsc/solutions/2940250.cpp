#include <fstream>

using namespace std;

ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");

int v[1026][1026],s1[1026], s2[1026];

void afisare(int i, int j)
{
    if(i>=1 && j>=1)
    {
        if(s1[i]==s2[j])
        {
            afisare(i-1,j-1);
            cout<<s1[i]<<" ";
        }
        else if(v[i-1][j]>v[i][j-1])
        {
            afisare(i-1,j);
        }
        else
        {
            afisare(i,j-1);
        }
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        cin>>s1[i];
    }
    for(int j=1; j<=m ; j++)
    {
        cin>>s2[j];
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(s1[i]==s2[j])
            {
                v[i][j]=v[i-1][j-1]+1;
            }
            else
            {
                v[i][j]=max(v[i-1][j],v[j][i-1]);
            }
        }
    }
    cout<<v[n][m]<<'\n';
    afisare(n,m);
    return 0;
}
