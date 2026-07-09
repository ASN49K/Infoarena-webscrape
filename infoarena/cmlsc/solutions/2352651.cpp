#include <iostream>
#include <fstream>

using namespace std;

int z[1025][1025];
int vx[1025],vy[1025];
int q[1025][1025];
int sir[1025];
int n,m;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int main()
{
    fin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        fin>>vy[i];
    }
    for(int i=1;i<=m;i++)
    {
        fin>>vx[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(vx[j] == vy[i])
            {
                z[i][j] = z[i-1][j-1] + 1;
                q[i][j] = 1;
            }
            else
            {
                if(z[i-1][j] >= z[i][j-1])
                {
                    z[i][j] = z[i-1][j];
                    q[i][j] = 2;
                }
                else
                {
                    z[i][j] = z[i][j-1];
                    q[i][j] = 3;
                }
            }
        }
    }
    fout<<z[n][m]<<"\n";
    int i=n;
    int j=m;
    int k = z[i][j];
    while(z[i][j] != 0)
    {
        if(q[i][j] == 1)
        {
            sir[k--] = vx[j];
            i--;
            j--;
        }
        else if(q[i][j] == 2)
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    for(int i=1;i<=z[n][m];i++)
    {
        fout<<sir[i]<<" ";
    }
    return 0;
}
