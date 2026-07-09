#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");

int n, m, o[100][100], a[100], b[100], sir[100], bst;

void citire()
{
    fin >> n;
    fin >> m;
    if(m>n)
    {
        int p=n;
        n=m;
        m=p;
    }
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
