#include <fstream>
#include <vector>
using namespace std;
ifstream in ("cmlsc.in");
ofstream out ("cmlsc.out");
int v1[1027],v2[1027];
int cmlsc[1027][1027];
vector<int> solutia;
int main()
{
    int n,m,i,j;
    in>>n>>m;
    for(i=1; i<=n; i++)
        in>>v1[i];
    for(i=1; i<=m; i++)
        in>>v2[i];
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            if(v1[i]==v2[j])
                cmlsc[i][j]=cmlsc[i-1][j-1]+1;
            else
                cmlsc[i][j]=max(cmlsc[i][j-1],cmlsc[i-1][j]);
    int l=cmlsc[n][m];
    for(i=n; i>0; i--)
        for(j=m; j>0; j--)
            if(v1[i]==v2[j]&&cmlsc[i][j]==l)
            {
                solutia.push_back(v1[i]);
                l--;
            }

    out<<cmlsc[n][m]<<'\n';
    for(i=cmlsc[n][m]-1; i>=0; i--)
        out<<solutia[i]<<' ';
    return 0;
}
