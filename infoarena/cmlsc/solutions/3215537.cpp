#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
vector <int> a, b, k;
int n, m;
int main()
{
    f >> n >> m;
    for (auto i = 0; i < n; ++i)
    {
        int x;
        f >> x;
        a.push_back(x);
    }
    for (auto i = 0; i < m; ++i)
    {
        int x;
        f >> x;
        b.push_back(x);
    }
    for (auto i : a)
        for (auto j : b)
            if (i == j)
                k.push_back(i);
    g << k.size() << '\n';
    for (auto i : k)
        g << i << ' ';
    f.close();
    g.close();
    return 0;
}

/*





*/
