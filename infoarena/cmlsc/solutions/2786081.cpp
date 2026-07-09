#include <bits/stdc++.h>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int a[1050][1050];
int sol[1050];
int loc = -1;


int main()
{
    int n, m;
    int x[1030], y[1030];

    f >> n >> m;

    for(int i = 0; i < n; i++)
        f >> x[i];

    for(int i = 0; i < m; i++)
        f >> y[i];

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            if(x[i - 1] == y[j - 1])
                a[i][j] = 1 + a[i - 1][j - 1];
            else
                a[i][j] = max(a[i -1][j], a[i][j - 1]);


    int i = n, j = m;

    while(i && j)
    {
        if(x[i - 1] == y[j - 1])
        {
            sol[++loc] = x[i - 1];
            i--; j--;
        }
        else
            if(a[i - 1][j] < a[i][j - 1])
                j--;
            else
                i--;
    }

    g << loc + 1 << '\n';


    for(int i = loc; i >= 0; i--)
        g << sol[i] << " ";


    return 0;
}
