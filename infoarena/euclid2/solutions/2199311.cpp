#include <fstream>

using namespace std;

int cmmdc(int a, int b)
{
    if (b == 0)
        return a;
    return cmmdc(b, a%b);
}

int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    int n;
    int a,b;
    f>>n;
    while (n>0)
    {
        n--;
        f>>a>>b;
        g<<cmmdc(a,b);
    }
    return 0;
}
