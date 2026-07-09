#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int mat[1025][1025];
int n, m;
int c1[1025], c2[1025];
vector <int> afis;

void readit()
{
    in>>n>>m;
    for(int i=1; i<=n; i++)
        in>>c1[i];
    for(int i=1; i<=m; i++)
        in>>c2[i];
}

int main()
{
    readit();
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            mat[i][j]=max(mat[i-1][j], mat[i][j-1])+(c1[i]==c2[j]);
        }
    }
    for(int i=1; i<=m; i++)
        if(mat[n][i]>mat[n][i-1]) afis.push_back(c2[i]);
    out<<afis.size()<<'\n';
    for(int i=0; i<afis.size(); i++) out<<afis[i]<<' ';
    return 0;
}
