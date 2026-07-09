#include <bits/stdc++.h>
#define NMAX 1030

using namespace std;

ifstream f ("cmlsc.in");
ofstream g ("cmlsc.out");

short n , m;
int a1[NMAX] , a2[NMAX];
int a[NMAX][NMAX];
vector < int > ans;

int main()
{
    short i , j;

    f >> n >> m;

    for(i = 1 ; i <= n ; i++)
        f >> a1[i];

    for(i = 1 ; i <= m ; i++)
        f >> a2[i];

    for(i = 1 ; i <= n ; i++)
        for(j = 1 ; j <= m ; j++)
            if(a1[i] == a2[j])
                a[i][j] = a[i - 1][j -  1] + 1;
            else a[i][j] = max(a[i - 1][j] , a[i][j - 1]);

    g << a[n][m] << '\n';

    short lin = n , col = m , lg = a[n][m];

    while(a[lin][col])
    {
        if(a[lin][col] == lg && a1[lin] == a2[col])
        {
            ans.push_back(a1[lin]);
            --lin;
            --col;
            --lg;
        }
        else
        {
            if(a[lin - 1][col] > a[lin][col - 1])
                --lin;
            else --col;
        }
    }

    for(i = ans.size() - 1 ; i >= 0 ; i--)
        g << ans[i] << ' ';

    return 0;
}
