#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n, m;
vector <int> a, b;
vector <vector <int> > v;
vector <int> r;

void lcs()
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(a[i] == b[j])
            {
                v[i][j] = v[i-1][j-1] + 1;
            }
            else
            {
                v[i][j] = max(v[i-1][j], v[i][j-1]);
            }
        }
    }
}

void get(int i, int j)
{
    if(i == 0 || j == 0)
    {
        return;
    }
    if(a[i] == b[j])
    {
        r.push_back(a[i]);
        get(i-1, j-1);
        return;
    }
    if(v[i][j-1] > v[i-1][j])
    {
        get(i, j-1);
        return;
    }
    get(i-1, j);
}


int main()
{
    cin >> n >> m;
    v.resize(n+1, vector <int> (m+1, 0));
    int t;
    a.push_back(0);
    b.push_back(0);
    for(int i = 0;i < n; i++)
    {
        cin >> t;
        a.push_back(t);
    }
    for(int i = 0;i < m; i++)
    {
        cin >> t;
        b.push_back(t);
    }
    lcs();
    get(n, m);
    cout << r.size() << "\n";
    for(int i = r.size()-1; i >= 0; i--)
        cout << r[i] << " ";

    return 0;
}
