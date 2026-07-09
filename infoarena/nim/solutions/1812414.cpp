#include <iostream>
#include <fstream>
using namespace std;
ifstream in("nim.in");
ofstream out("nim.out");
const int maxn = 10005;
int v[maxn];
void solve()
{
    int n;
    in >> n;
    int s;
    in >> s;
    for(int i = 2; i <= n; i++)
    {
        in >> v[i];
        s = s ^ v[i];
    }
    if(s > 0)
    {
        out << "DA" << "\n";
        return;
    }
    out << "NU" << "\n";
}

int main()
{
    int T;
    in >> T;
    for(int i = 1; i <= T; i++)
        solve();
    return 0;
}
