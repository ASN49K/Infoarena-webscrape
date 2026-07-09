#include <iostream>
#include <fstream>
#include <stack>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int a[1025][1025], v1[1025], v2[1025], m, n;
stack<int> b;

int max(int a, int b)
{
    if (a > b)
        return a;
    return b;
}

void citire()
{
    fin >> m >> n;
    for (int i = 1; i <= m; i++)
    {
        int x;
        fin >> x;
        v1[i] = x;
    }
    for (int i = 1; i <= n; i++)
    {
        int x;
        fin >> x;
        v2[i] = x;
    }
}

int lcs()
{
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (v1[i] == v2[j])
                a[i][j] = a[i - 1][j - 1] + 1;
            else a[i][j] = max(a[i][j - 1], a[i - 1][j]);
        }
    }
    return a[m][n];
}

void backtrack(int i, int j)
{
    if (i == 0 || j == 0)
        return;
    if (v1[i] == v2[j])
    {
        b.push(v1[i]);
        backtrack(i - 1, j - 1);
    }
    else if (a[i][j - 1] > a[i - 1][j])
        backtrack(i, j - 1);
    else backtrack(i - 1, j - 1);
}


int main()
{
    citire();
    cout << lcs() << '\n';
    backtrack(m, n);
    while (!b.empty())
    {
        cout << b.top()<<' ';
        b.pop();
    }
}

