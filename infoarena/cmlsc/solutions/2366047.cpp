#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

std::ifstream in("cmlsc.in");
std::ofstream out("cmlsc.out");

using namespace std;
int mat[1030][1030];
int sir[1030],sir2[1030];
int n,m;
vector < int > sol;

void traceback(int x , int y)
{
    if(x==0 || y==0)
    {
        return;
    }
    if(sir[x]==sir2[y])
    {
        sol.push_back(sir[x]);
        traceback(x-1,y-1);
    }
    else
    {
        if(mat[x][y-1]>mat[x-1][y])
        {
            traceback(x,y-1);
        }
        else
        {
            traceback(x-1,y);
        }
    }
}


int main()
{
    in>>n>>m;
    for(int i=1;i<=n;i++)
    {
        in>>sir[i];
    }
    for(int j = 1;j<=m;j++)
    {
        in>>sir2[j];
    }
    for(int i = 1;i<=n;i++)
    {
        for(int j = 1;j<=m;j++)
        {
            mat[i][j] = max(mat[i-1][j] , mat[i][j-1]);
            if(sir[i] == sir2[j])
            {
                mat[i][j] = mat[i-1][j-1] + 1;
            }
        }
    }
    out<<mat[n][m]<<'\n';
    traceback(n,m);
    reverse(sol.begin(),sol.end());
    for(auto e : sol)
    {
        out<<e<<" ";
    }
    return 0;
}
