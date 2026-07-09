#include<fstream>
#include<deque>
#define nx 1027
using namespace std;
int n,m,i,j,l,v[nx],w[nx],a[nx][nx];
deque<int>d;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int main()
{
    fin>>n>>m;
    for(i=1;i<=n;i++)fin>>v[i];
    for(i=1;i<=m;i++)fin>>w[i];

    for(i=1;i<=n;i++)
       for(j=1;j<=m;j++)if(v[i]==w[j])a[i][j]=1+a[i-1][j-1];
                                 else a[i][j]=max(a[i-1][j],a[i][j-1]);

    l=a[n][m];
    while(l)
    {
        while(a[n-1][m]==l)n--;
        while(a[n][m-1]==l)m--;
        d.push_back(v[n]);
        l--;
    }

    fout<<d.size()<<'\n';
    while(!d.empty())fout<<d.back()<<' ',d.pop_back();
    return 0;
}
