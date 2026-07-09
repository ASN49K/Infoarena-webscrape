#include <fstream>
#include <algorithm>
using namespace std;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
int v1[1030], v2[1030];
int rasp[1030];
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
    cout<<mat[n][m]<<'\n';
    int k=1;
    int i1=n, j1=m;
    while ((i1>=1 || j1>=1) && mat[i1][j1])
    {
        if (mat[i1][j1]==mat[i1-1][j1-1]+1)
        {
            rasp[k]=v1[i1];
            k++;
            i1--;
            j1--;
        }
        else
            if (mat[i1-1][j1]>mat[i1][j1-1])
                j1--;
            else
                i1--;
    }
    for (int i=k-1; i>=1; i--)
        cout<<rasp[i]<<' ';
    return 0;
}
