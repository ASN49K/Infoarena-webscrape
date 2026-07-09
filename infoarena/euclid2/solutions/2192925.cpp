#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int main()
{
    int x, y;
    f>>x>>y;
    while(x!=y)
    {
    if(x>y) x=x-y;
    else y=y-x;
    }
    g<<x;
    return 0;
}
