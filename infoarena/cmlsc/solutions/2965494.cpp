#include <fstream>
#include <vector>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n,m;

int d[1105][1105];
int a[1105];
int b[1105];
vector <int> sol;
int main()
{
    fin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        fin>>a[i];
    }
    for(int i=1;i<=m;i++)
    {
        fin>>b[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i]==b[j])
            {
                d[i][j]=d[i-1][j-1]+1;
            }
            else
            {
                d[i][j]=max(d[i-1][j],d[i][j-1]);
            }
        }
    }
    fout<<d[n][m]<<'\n';
    int l = d[n][m];
    for(int i=n,j=m;i>=1;)
    {
        if(a[i]==b[j])
        {
            sol.push_back(a[i]);
            i--;
            j--;
        }
        else
        {
            if(d[i-1][j]<d[i][j-1])
            {
                j--;
            }
            else
                i--;
        }
    }

    while(sol.empty()==false)
        fout<<sol.back()<<' ',sol.pop_back();

}
