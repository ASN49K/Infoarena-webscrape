#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n, m, s[1050], p[1050];
int mat[1024][1024];
vector<int> solutie;
void citire()
{
    fin >> n >> m;
    for(int i = 1; i <= n; i++)
        fin >> s[i];
    for(int j = 1; j <= m; j++)
        fin >> p[j];
}

int dp(int i, int j)
{
    if(i == n+1 || j == m+1)
        return 0;
    if(s[i] == p[j])
    {
        solutie.push_back(s[i]);
        if(!mat[i+1][j+1])
            mat[i+1][j+1] = dp(i+1, j+1);
        return 1+mat[i+1][j+1];
    }
    else
    {
        if(!mat[i][j+1])
            mat[i][j+1] = dp(i, j+1);
        if (!mat[i+1][j])
        {
            mat[i+1][j] = dp(i+1, j);
        }
        return max(mat[i][j+1], mat[i+1][j]);
    }
}

int main()
{
    citire();
    fout << dp(1, 1) << '\n';
    for(int i = solutie.size()-1; i >= 0; i--)
        fout << solutie[i] << ' ';
    return 0;
}
