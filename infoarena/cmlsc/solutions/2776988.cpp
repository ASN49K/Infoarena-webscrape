#include<bits/stdc++.h>

using namespace std;

ifstream fin("clmsc.in");
ofstream fout("clmsc.out");
#define cin fin
#define cout fout

#define N 1030
int n, m, nr, v[N], w[N], s[N], d[N][N];

int main()
{
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> v[i];
    }
    for(int i = 1 ; i <= m ; i++)
    {
        cin >> w[i];
    }
    for(int i = 1 ; i <= n ; i++)
    {
        for(int j = 1 ; j <= m ; j++)
        {
            if(v[i] == w[j])
            {
                d[i][j] = d[i-1][j-1]+1;
            }
            else d[i][j] = max(d[i-1][j],d[i][j-1]);
        }
    }
    for(int i = n, j = m ; i ;)
    {
        if(v[i] == w[j])
        {
            s[++nr] = v[i];
            i--, j--;
        }
        else if(d[i-1][j] < d[i][j-1])j--;
        else i--;
    }
    cout << nr << '\n';
    for(int i =nr ; i ; i--)
    {
        cout << s[i] << ' ';
    }
    cout << d[n][m] << '\n';
    return 0;
}
