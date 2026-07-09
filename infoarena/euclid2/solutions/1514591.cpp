#include <iostream>
#include <fstream>

using namespace std;

ifstream fi("euclid2.in");
ofstream fo("euclid2.out");

int n, a, b;

void solve();
void euclid();

int main()
{

    solve();

    fi.close();
    fo.close();

    return 0;
}

int euclid(int a, int b)
{
    if (b == 0) return a;
    return euclid(b, a%b);
}

void solve()
{
    fi >> n;
    for (int i = 1; i <= n; i++)
    {
        fi >> a >> b;
        fo << euclid(a, b) << "\n";
    }

}
