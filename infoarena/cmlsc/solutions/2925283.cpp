#include <iostream>

using namespace std;

int n, m, v[1030][1030], x[1030], y[1030], ans[1030], cnt=0;

void backtrack(int i, int j)
{
    if (x[i]!=0 and y[j]!=0)
    {if (x[i]==y[j])
        {
        ans[cnt]=x[i];
        cnt++;
        }
    if (v[i][j-1]>v[i-1][j])
        backtrack(i, j-1);
    backtrack(i-1, j);
    }
}



int main()
{

    cin >> n >> m;
    for (int i=1; i<=n; i++)
        cin >> x[i];
    for (int j=1; j<=m; j++)
        cin >> y[j];

    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
    {
        if (x[i]==y[j])
            v[i][j]=v[i-1][j-1]+1;
        else
            v[i][j]=max(v[i-1][j], v[i][j-1]);
    }

    cout << v[n][m] << '\n';



    backtrack(n, m);

    if (v[n][m]!=0)
    for (int i=cnt-1; i>=0; i--)
        cout << ans[i] << " ";



    return 0;
}
