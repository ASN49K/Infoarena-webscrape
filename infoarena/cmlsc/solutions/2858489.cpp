//#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");

int n,m,v1[1025],v2[1025],a[1025][1025];
vector <int> v;
int main()
{
    cin>>n>>m;
    for (int i=1; i<=n; i++)
        cin>>v1[i];
    for (int i=1; i<=m; i++)
        cin>>v2[i];
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
            if (v1[i]==v2[j])
                a[i][j]=a[i-1][j-1]+1;
            else
                a[i][j]=max(a[i-1][j],a[i][j-1]);
    while (n and m)
    {
        if (v1[n]==v2[m])
        {
            v.push_back(v1[n]);
            n--;
            m--;
        }
        else if (a[n-1][m]<a[n][m-1])
            m--;
        else
            n--;
    }
    cout<<v.size()<<'\n';
    for (int i=v.size()-1; i>=0; i--)
        cout<<v[i]<<" ";
}
