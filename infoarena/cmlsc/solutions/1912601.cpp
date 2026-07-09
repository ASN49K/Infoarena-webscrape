#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");

int n, m, o[1026][1026], a[1026], b[1026], sir[1024], bst;

void citire()
{
    fin >> n;
    fin >> m;
    for(int i=1;i<=n;i++)
        fin >> a[i];
    for(int i=1;i<=m;i++)
        fin >> b[i];
}

int main()
{
    citire();
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i]==b[j])
                o[i][j]=1+o[i-1][j-1];
            else
                o[i][j]=max(o[i-1][j], o[i][j-1]);
        }
    }
    fout << o[n][m] << '\n';
    for (int i = n, j = m; i; ){
        if (a[i] == b[j])
            sir[++bst] = a[i], --i, --j;
        else if (o[i-1][j] < o[i][j-1])
            --j;
        else
            --i;
    }
    for(int i=o[n][m];i>=1;i--)
        fout << sir[i] << " ";

    return 0;
}
