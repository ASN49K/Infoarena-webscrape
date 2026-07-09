#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
ifstream f ("cmlsc.in");
ofstream g ("cmlsc.out");

int mat[1025][1025];
int sir1[1025],sir2[1025];
vector <int> sub;

int main()
{
    int n,m,x=0;

    f>>n;
    f>>m;

    for (int i=1; i<=n; i++)
    {
        f>>sir1[i];
    }

    for (int i=1; i<=m; i++)
    {
        f>>sir2[i];
    }

    for (int i=1; i<=m; i++)
    {
        for (int j=1; j<=n; j++)
        {
            if (sir1[j]==sir2[i])
                mat[i][j]=mat[i-1][j-1]+1;
            else
                mat[i][j]=max(mat[i][j-1],mat[i-1][j]);
            if (mat[i][j]>x)
            {
                sub.push_back(sir1[j]);
                x=mat[i][j];
            }
        }
    }
    g<<mat[m][n]<<'\n';

    for (int i=0; i<sub.size();i++)
    {
        g<<sub[i]<<" ";
    }
    f.close();
    g.close();
    return 0;
}
