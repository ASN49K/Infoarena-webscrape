#include <fstream>
#include <algorithm>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int t, a, b;

int euclid(int x, int y)
{
    if(!y)
        return x;
    else
        return euclid(y, x % y);
}

int main()
{
    f >> t;
    while(t)
    {
        f >> a >> b;
        if(a < b)
            swap(a, b);

        g << euclid(a, b) << '\n';

        t--;
    }

    f.close();
    g.close();

    return 0;
}
