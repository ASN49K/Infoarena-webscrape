#include <bits/stdc++.h>

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int a[1025], b[1025], dp[1025][1025], iMax, jMax;
int coada[1025], l;

int main()
{
    in >> iMax >> jMax;

    for(int i = 1; i <= iMax; i++)
        in >> a[i];

    for(int j = 1; j <= jMax; j++)
        in >> b[j];

    for(int i = 1; i <= iMax; i++)
        for(int j = 1; j <= jMax; j++)
            dp[i][j] = max( max(dp[i-1][j], dp[i][j-1]),
                           dp[i-1][j-1] + (a[i] == b[j] ? 1 : 0) );

    int i = iMax, j = jMax;

    while(i != 0 && j != 0)
    {
        if(a[i] == b[j])
        {
            coada[++l] = a[i];
            i--;
            j--;
        }
        else if(dp[i-1][j] >= dp[i][j-1])
            i--;
        else
            j--;
    }

    out << dp[iMax][jMax] << '\n';

    for(int i = l; i >= 1; i--)
        out << coada[i] << ' ';

    return 0;
}
