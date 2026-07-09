#include <bits/stdc++.h>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int NMAX = 1024;

int n, m; int cnt;
int a[NMAX+1];
int b[NMAX+1];
int mat[NMAX+1][NMAX+1];
vector <int> ans;

int main()
{
    fin >> n >> m;
    for(int i=1; i<=n; i++)
        fin >> a[i];
    for(int i=1; i<=m; i++)
        fin >> b[i];
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(a[i] == b[j])
                mat[i][j] = 1+mat[i-1][j-1];
            else if(a[i] != b[j])
                mat[i][j] = max(mat[i-1][j], mat[i][j-1]);
        }
    }
    fout << mat[n][m] << '\n';
    int i=n, j=m;
    while(i>=1 && j>=1)
    {
        if(a[i] == b[j])
            ans.push_back(a[i]),i--, j--;
        else if(mat[i-1][j] > mat[i][j-1])
            i--;
        else
            j--;
    }
    for(int i=mat[n][m]-1; i>=0; i--)
        fout << ans[i] << ' ';
    return 0;
}
