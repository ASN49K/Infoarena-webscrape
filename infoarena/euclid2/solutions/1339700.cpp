#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");

int Euclid(int a, int b)
{
    if (!b) return a;
    return Euclid(b,a%b);
}

int main()
{
    int i,x,y;
    f>>i;
    while (i--)
        {
            f>>x>>y;
            g<<Euclid(x,y);
        }
    return 0;
}
