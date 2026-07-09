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
        for(int j=1; j<=m; j++)
            if(c1[i]==c2[j]) mat[i][j]=mat[i-1][j-1]+1;
            else mat[i][j]=max(mat[i-1][j], mat[i][j-1]);
    int i=n, j=m;
    while(i)
    {
        if(c1[i]==c2[j]) afis.push_back(c1[i]), i--, j--;
        else if(mat[i-1][j]<mat[i][j-1]) j--;
        else i--;
    }
    out<<afis.size()<<'\n';
    while(!afis.empty()) out<<afis.back()<<' ', afis.pop_back();
    return 0;
}
