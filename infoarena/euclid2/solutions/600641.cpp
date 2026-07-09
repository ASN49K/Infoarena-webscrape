#include <fstream>
using namespace std;

int n;

inline int cmmdc(int a, int b)
{
    if(b == 0) return a;
    return cmmdc(b, a % b);
}

int main()
{
    int i, a, b;

    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f >> n;
    for(i = 1; i <= n; ++i)
    {
        f >> a >> b;
        g << cmmdc(a, b) << '\n';
    }

    g.close();
    return 0;
}
