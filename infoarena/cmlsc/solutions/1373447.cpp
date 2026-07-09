#include<fstream>
#include<vector>
#define Nmax 1099
using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int n,m,a[Nmax],b[Nmax],d[Nmax][Nmax];
vector <int> sol;

void Nrmax()
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(a[i]==b[j]) d[i][j]=d[i-1][j-1]+1;
                else if(d[i-1][j]>d[i][j-1]) d[i][j]=d[i-1][j];
                                        else d[i][j]=d[i][j-1];
}

void build()
{
    int i=n,j=m;
    while(i>0 && j>0)
    {
        if(a[i]==b[j])
        {
            sol.push_back(a[i]);
            --i;
            --j;
        }
        else if(d[i-1][j]>d[i][j-1]) --i;
                                else --j;
    }
}

int main()
{
    f>>n>>m;
    for(int i=1;i<=n;i++) f>>a[i];
    for(int j=1;j<=m;j++) f>>b[j];
    Nrmax();
    build();
    g<<d[n][m]<<'\n';
    for(int i=sol.size()-1;i>=0;--i) g<<sol[i]<<' ';
    g<<'\n';
    f.close();g.close();
    return 0;
}
