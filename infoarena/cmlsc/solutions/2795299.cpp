#include <iostream>
#include <fstream>
#include <stack>
#define MAXN 1030

using namespace std;

ifstream fin ("cmlsc.in");
ofstream fout("cmlsc.out");

int n, m, a[MAXN], b[MAXN], mat[MAXN][MAXN];
stack<int> sol;
int main()
{
    fin >> n >> m;
    for(int i = 1; i <= n; i++) fin >> a[i];
    for(int i = 1; i <= m; i++) fin >> b[i];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            if(a[i] == b[j]) mat[i][j] = mat[i-1][j-1]+1;
            else mat[i][j] = max(mat[i-1][j], mat[i][j-1]);
    int k = mat[n][m], j = m;
    fout << k << "\n";
    for(int i = n; i+1; i--)
        if(mat[i][j] == mat[i-1][j-1]+1)
            sol.push(a[i]), j--;
    while(!sol.empty()) fout << sol.top() << " ", sol.pop();
    return 0;
}
