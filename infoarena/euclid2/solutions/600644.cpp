#include <fstream>
using namespace std;

int n;

inline int cmmdc(int a, int b)
{

}

int main()
{
    int i, a, b, ax;

    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f >> n;
    for(i = 1; i <= n; ++i)
    {
        f >> a >> b;
        while(b)
        {
            ax = a % b;
            a = b;
            b = ax;
        }
        g << a << '\n';
    }

    g.close();
    return 0;
}
