#include <fstream>

using namespace std;
ifstream in ("cmlsc.in");
ofstream out ("cmlsc.out");
int v1[1027],v2[1027];
int cmlsc[1027][1027];
int solutia[1027];
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
    i=n;
    j=m;
    int a=0;
    while(i)
    {
        if(v1[i]==v2[j])
        {
            solutia[++a]=v1[i];
            i--;
            j--;
        }
        if(cmlsc[i][j-1]>cmlsc[i-1][j])
            j--;
        else
            i--;
    }
    out<<cmlsc[n][m]<<'\n';
    for(i=cmlsc[n][m];i>0;i--)
        out<<solutia[i]<<' ';
    return 0;
}
