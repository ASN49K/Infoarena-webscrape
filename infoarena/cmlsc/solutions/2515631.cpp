#include <bits/stdc++.h>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n, m, a[1026], b[1026],  d[1026][1026], l = 1, sir[1026];

int main()
{
    fin >> n >> m;

    for(int i = 1; i <= n; i++)
    {
        fin >> a[i];
    }

    for(int i = 1; i <= m; i++)
    {
        fin >> b[i];
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(a[i] == b[j])
            {
                d[i][j] = 1 + d[i-1][j-1];
            }
            else
            {
                d[i][j] = max(d[i][j - 1], d[i - 1][j]);
            }
        }
    }

    l = 1;
    int i, j;

    for(i = n, j = m; i; )
    {
        if(a[i] == b[j])
        {
            sir[l++] = a[i];
            i--;
            j--;
        }
        else if(d[i-1][j] < d[i][j-1])
        {
            j--;
        }
        else
        {
            i--;
        }
    }

    fout << l-1 << endl;

    for(i = l-1; i >= 1; i--)
    {
        fout << sir[i] << ' ' ;
    }

    return 0;
}
