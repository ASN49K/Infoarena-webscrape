#include <iostream>
#include <fstream>

using namespace std;

int n, m, v[1040][1040], x[1040], y[1040], ans[1040], cnt=0;

void backtrack(int i, int j)
{
    if (i>=0 and j>=0){
        if (x[i]==y[j]){
            ans[cnt]=x[i];
            cnt++;
        }
        if (i!=0 and j!=0)
        {
            if (v[i][j-1]>v[i-1][j])
                backtrack(i, j-1);
            backtrack(i-1, j);
        }
    }
}



int main()
{
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");

    f >> n >> m;
    for (int i=1; i<=n; i++)
        f >> x[i];
    for (int j=1; j<=m; j++)
        f >> y[j];

    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
    {
        if (x[i]==y[j])
            v[i][j]=v[i-1][j-1]+1;
        else
            v[i][j]=max(v[i-1][j], v[i][j-1]);
    }

    g << v[n][m] << '\n';



    backtrack(n, m);

    if (cnt>0)
    for (int i=cnt-1; i>=0; i--)
        g << ans[i] << " ";



    return 0;
}
