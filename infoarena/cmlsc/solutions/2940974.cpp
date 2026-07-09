#include <fstream>

using namespace std;

ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");

int v[1027][1027],s1[1024],s2[1024];

void citire(int &m, int &n)
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>s1[i];
    }
    for(int i=1;i<=m;i++)
    {
        cin>>s2[i];
    }
}

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
            afisare(i-1 , j);
        }
        else
        {
            afisare(i,j-1);
        }
    }

}

void rezolvare(int n, int m)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s1[i]==s2[j])
            {
                v[i][j]=v[i-1][j-1]+1;
            }
            else if(v[i-1][j]>v[i][j-1])
            {
                v[i][j]=v[i-1][j];
            }
            else
            {
                v[i][j]=v[i][j-1];
            }
        }
    }
    cout<<v[n][m]<<'\n';
    afisare(n,m);
}

int main()
{
    int n,m;
    citire(m,n);
    rezolvare(n,m);
    return 0;
}
