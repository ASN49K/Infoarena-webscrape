#include <fstream>

using namespace std;

int Euclid (int a, int b)
{
    int r;
    while (b)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

void Solve()
{
    int t, n, m;
    ifstream fin ("euclid2.in");
    ofstream fout ("euclid2.out");
    fin >> t;
    while (t--)
    {
        fin >> n >> m;
        fout << Euclid(n, m) << "\n";
    }
}
int main()
{
    Solve();
    return 0;
}
