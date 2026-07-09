#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int t;

int euclid(int a, int b)
{
    if(!b) return a;
    return euclid(b, a%b);
}

int main()
{
    f >> t;
    while(t--)
        {   int a, b;
            f >> a >> b;
            g << euclid(a, b) << '\n';
        }

    return 0;
}
