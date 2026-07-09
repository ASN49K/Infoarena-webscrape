#include <bits/stdc++.h>

using namespace std;
int a[1026], b[1026], m, n, d[1026][1026];
int main()
{
    // d[i][j] -> lungimea celui mai lung subsir ce se poate forma cu primele i elemente din a si primele j elemente din b
    /*
    d[i][j] = { max(d[i - 1][j], d[i][j - 1]) , a[i] != b[j]
                1 + d[i - 1][j - 1] , a[i] == a[j]
    */
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= m; i++)
        cin >> b[i];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
        {
            if(a[i] == b[j])
                d[i][j] = 1 + d[i - 1][j - 1];
            else
                d[i][j] = max(d[i - 1][j], d[i][j - 1]);
        }
    cout << d[n][m] << '\n';
    /*cout << "  ";
    for(int i = 1; i <= m; i++)
        cout << i << " ";
    cout << '\n';
    for(int i = 1; i <= n; i++)
    {
        cout << i << " ";
        for(int j = 1; j <= m; j++)
            cout << d[i][j] << " ";
        cout << '\n';
    }
    */
    int i = n;
    int j = m;
    vector<int>sol;
    while( i > 0 && j > 0)
    {

        if(a[i] == b[j])
        {
            sol.push_back(a[i]);
            i--;
            j--;
        }
        else
        {
            if(d[i][j - 1] > d[i - 1][j])
                j--;
            else
                i--;

        }
    }
    for(int i = sol.size() - 1; i >= 0; i--)
        cout << sol[i] << " ";
    return 0;
}
