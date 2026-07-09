#include <fstream>
#include <algorithm>
using namespace std;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
int v1[1030], v2[1030];
int mat[1030][1030];
int maxx(int a, int b)
{
    if (a>b)
        return a;
    return b;
}
int main()
{
    int n, m;
    cin>>n>>m;
    for (int i=1; i<=n; i++)
        cin>>v1[i];
    for (int i=1; i<=m; i++)
        cin>>v2[i];
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
        {
            if (v1[i]==v2[j])
                mat[i][j]=mat[i-1][j-1]+1;
            else
                mat[i][j]=maxx(mat[i-1][j],mat[i][j-1]);
        }
    cout<<mat[n][m];
    return 0;
}
