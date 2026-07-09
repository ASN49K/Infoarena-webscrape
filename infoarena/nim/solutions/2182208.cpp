#include <iostream>
#include <fstream>
using namespace std;
ifstream in("nim.in");
ofstream out("nim.out");

void solve()
{
    int n;
    in >> n;
    int rez = 0;
    for(int i = 1; i <= n; i++)
    {
        int x;
        in >> x;
        rez = rez ^ x;
    }
    if(rez == 0)
        out << "NU";
    else
        out << "DA";
    out << "\n";
    return;
}

int main()
{
    int T;
    in >> T;
    for(int i = 1; i <= T; i++)
        solve();
    return 0;
}
