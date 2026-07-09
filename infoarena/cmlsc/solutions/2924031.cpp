// cel mai lung subsir comun.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <queue>

#define ll long long
using namespace std;
ll n, m, i,j;
int main()
{
    cin >> n >> m;
    vector<ll>x(n + 1, 0), y(m + 1, 0);
    for (i = 1; i <= n; ++i)cin >> x[i];
    for (i = 1; i <= m; ++i)cin >> y[i];

    vector<vector<ll>>d(n + 1, vector<ll>(m + 1, 0));
    for (i = 1; i <= n; ++i)
    {
        for (j = 1; j <= m; ++j)
        {
            if (x[i] == y[j])
            {
                d[i][j] = d[i - 1][j - 1] + 1;
            }
            else d[i][j] = max(d[i - 1][j], d[i][j - 1]);
        }
    }
    i = n;
    j = m;
    ll db = d[n][m];
    deque<ll>res;
    while (db)
    {
        if (x[i] == y[j])
        {
            res.push_front(x[i]);
            --i;
            --j;
            db--;
        }
        else if (d[i][j - 1] > d[i - 1][j])--j;
        else --i;

    }
    cout << d[n][m] << "\n";
    for (i = 0; i < res.size(); ++i)cout << res[i]<<" ";
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
