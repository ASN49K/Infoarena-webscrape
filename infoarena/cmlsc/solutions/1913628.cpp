#include <fstream>
#include <vector>

using namespace std;

ifstream cin ("cmlsc.in" );
ofstream cout("cmlsc.out");

vector <int> a, b, d;

void read()
{
    int n, m;
    cin >> n >> m;
    a.resize(n + 1);
    b.resize(m + 1);

    for (int i = 1; i < a.size(); cin >> a[i++]);
    for (int i = 1; i < b.size(); cin >> b[i++]);
}

void solve()
{
    vector <vector <int> > x(a.size() );
    for (int i = 0; i < x.size(); x[i++].resize(b.size() ));

    for (int i = 1; i < x.size(); i++)
    {
        for (int j = 1; j < x[i].size(); j++)
        {
            if (a[i] == b[j]) x[i][j] = x[i - 1][j - 1] + 1;
                else x[i][j] = max(x[i - 1][j], x[i][j - 1]);
        }
    }

    int i = a.size() - 1, j = b.size() - 1;
    for (; i && j; )
    {
        if (a[i] == b[j]) d.push_back(a[i]), i--, j--;
            else
                if (x[i - 1][j] > x[i][j - 1]) i--; else j--;
    }
}

void write()
{
    cout << d.size() << '\n';
    for (int i = d.size() - 1; i >= 0; i--)
        cout << d[i] << ' ';
}

int main()
{
    read();

    solve();

    write();

    return 0;
}
