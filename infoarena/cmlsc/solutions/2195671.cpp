#include <fstream>
#include <vector>
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
vector<int>r;
const int N=1024;
int v1[N],v2[N],n,m,d[N][N];
void LCS(int i,int j)
{
    if(i==0 || j==0)
        return;
    else if(v1[i]==v2[j])
    {
        r.push_back(v1[i]);
        return LCS(i-1,j-1);
    }
    else
    {
     if(d[i-1][j]>d[i][j-1])
        return LCS(i-1,j);
     else
        return LCS(i,j-1);
    }
}
int main()
{
    in>>n>>m;
    for(int i=1;i<=n;i++)
        in>>v1[i];
    for(int i=1;i<=m;i++)
        in>>v2[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            d[i][j]=max(d[i-1][j],d[i][j-1]);
            if(v1[i]==v2[j])
                d[i][j]++;
        }
    }
    LCS(n,m);
    out<<r.size()<<'\n';
    for(int i=r.size()-1;i>=0;i--)
        out<<r[i]<<' ';
    return 0;
}
