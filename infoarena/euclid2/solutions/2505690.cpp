#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int t;

int main()
{
    f >> t;

    for(int i=1, a, b; i<=t; ++i)
    {
        f >> a >> b;

        while(b)
        {
            int r=a%b;
            a=b;
            b=r;
        }

        g << a << '\n';
    }

    f.close();
    g.close();

    return 0;
}
