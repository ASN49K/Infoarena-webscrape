#include <fstream>
#include <cmath>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n,m,v[1030],x[1030],com[1030][1030];
void det(int i, int j)
{
    if(i<=0 || j<=0) return;
    if(v[i]==x[j])
    {
        det(i-1,j-1);
        fout << v[i] << " ";
    }
    else
    {
        if(com[i-1][j]>com[i][j-1]) det(i-1,j);
        else det(i,j-1);
    }
}
int main()
{
    fin >> n >> m;
    for(int i=1;i<=n;i++)
        fin >> v[i];
    for(int j=1;j<=m;j++)
        fin >> x[j];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(v[i]==x[j]) com[i][j]=com[i-1][j-1]+1;
            else com[i][j]=max(com[i-1][j],com[i][j-1]);
        }
    }
    fout << com[n][m] << "\n";
    det(n,m);
    return 0;
}
