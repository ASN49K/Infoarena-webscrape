#include <cstdio>
#include <iostream>
using namespace std;

int M[1025][1025];

int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);
    int n, m, s1[1100], s2[1100];
    int P[1025];
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> s1[i];
    for(int i = 1; i <= m; i++)
        cin >> s2[i];

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            if(s1[i] == s2[j])
                M[i][j] = M[i-1][j-1] + 1;
            else
                M[i][j] = max(M[i][j-1], M[i-1][j]);

    int x = 0;
    int i = n, j = m;
    while(M[i][j] != 0)
    {
        while(M[i][j] == M[i-1][j]) i--;
        while(M[i][j] == M[i][j-1]) j--;
        P[x++] = s2[j];
        i--; j--;
    }
    cout << M[n][m] << '\n';
    for(int l = x-1; l >= 0; l--)
        cout << P[l] << ' ';
    return 0;
}
