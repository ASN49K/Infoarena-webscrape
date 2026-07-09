#include <fstream>

using namespace std;

int main()
{
    ofstream g("cmmdc.out");
    ifstream f("cmmdc.in");
    int a, b;
    f >> a >> b;

    while (a != b)
    {
        ((a > b)? a:b) = ((a > b)? a:b) - ((a < b)? a:b);
    }
    g << a;
    f.close();
    g.close();

    return 0;
}
