#include <iostream>
#include <fstream>
#include <stack>

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int a[1030], b[1030], v[1030][1030];
int n, m;

void scan()
{
    in >> n >> m;

    for(int i = 1; i <= n; i++)
        in >> a[i];

    for(int i = 1; i <= m; i++)
        in >> b[i];
}

void solve()
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(a[i] == b[j])
                v[i][j] = v[i-1][j-1] + 1;
            else
                v[i][j] = max(v[i-1][j], v[i][j-1]);
        }
    }

    out << v[n][m] << '\n';
}

void retrace()
{
    int i = n, j = m;
    stack<int> q;

    while(min(i, j) >= 1)
    {
        q.push(a[i]);

        i--;
        j--;

        while((min(i,j) >= 1) && (a[i] != b[j]))
        {
            if(v[i-1][j] > v[i][j-1])
                i--;
            else
                j--;
        }
    }

    while(!q.empty())
    {
        out << q.top() << ' ';

        q.pop();
    }
}

int main()
{
    scan();

    solve();

    retrace();

    return 0;
}
