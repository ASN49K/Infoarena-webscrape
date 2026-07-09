#include <bits/stdc++.h>
#define ll long long
#define lli long long int
#define endl "\n"
using namespace std;
    int matrix[1050][1050],a[1050],b[1050];
    int n,m;
    bool shown = false;
    ifstream fin("cmlsc.in");
    ofstream fou("cmlsc.out");
void LCA()
{
    for(int i=1;i<=n;i++)
        matrix[i][0] = 0;
    for(int j=1;j<=m;j++)
        matrix[0][j] = 0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        if (a[i] == b[j])
            matrix[i][j] = matrix[i-1][j-1] + 1;
        else matrix[i][j] = max(matrix[i][j-1],matrix[i-1][j]);
}

void build(int i, int j)
{
    if (i == n+1 || j == m+1)
        return;
    if (a[i] == b[j])
    {
        fou << a[i] << " ";
        build(i+1, j+1);
    } else
          if (matrix[i][j+1] > matrix[i+1][j])
            build(i, j+1);
            else build(i+1, j);
}

int main()
{    	//
    fin >> n >> m;
    for(int i=1;i<=n;i++)
        fin >> a[i];
    for(int i=1;i<=m;i++)
        fin >> b[i];
    //cout << n << ' ' << m;
    LCA();
    int x = matrix[n][m];
    fou << x << "\n";
    //fou << n;
    build(1,1);
    return (0);
}
