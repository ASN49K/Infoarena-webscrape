#include <bits/stdc++.h>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int n, m, v1[1030], v2[1030], sir[1030], k;
int d[1030][1030];

int main()
{
    f >> n >> m;
    for(int i = 1; i <= n; i++)
        f >> v1[i];
    for(int i = 1; i <= m; i++)
        f >> v2[i];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            if(v1[i] == v2[j])
                d[i][j] = d[i - 1][j - 1] + 1;
            else
                d[i][j] = max(d[i - 1][j], d[i][j - 1]);                                                                                                                                                                                                              ;

    for(int i = n, j = m; i && j;)
    {
        if(v1[i] == v2[j])
            sir[++k] = v1[i], i--, j--;
        else if(d[i - 1][j] < d[i][j - 1])
            j--;
        else
            i--;

    }
    g << k << "\n";
    for(int i = k; i; i--)
        g << sir[i] << " ";
    return 0;
}
