#include <fstream>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int v1[256],v2[256],m,n,l[256][256],p[256][256];
void afisare(int i, int j)
{
    if(i>0&&j>0)
        if(p[i][j]==1)
        {
            afisare(i-1,j-1);
            fout<<v1[i]<<' ';
        }
        else if(p[i][j]==2)
            afisare(i-1,j);
        else afisare(i,j-1);
}
int main()
{
    fin>>n>>m;
    for(int i=1; i<=n; i++)
        fin>>v1[i];
    for(int i=1; i<=m; i++)
        fin>>v2[i];

    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            if(v1[i]==v2[j])
            {
                l[i][j]=l[i-1][j-1]+1;
                p[i][j]=1;
            }
            else if(l[i-1][j]>l[i][j-1])
            {
                l[i][j]=l[i-1][j];
                p[i][j]=2;
            }
            else
            {
                l[i][j]=l[i][j-1];
                p[i][j]=3;
            }
    fout<<l[n][m]<<endl;
    afisare(n,m);
    return 0;
}
