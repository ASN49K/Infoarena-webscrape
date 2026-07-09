#include <fstream>

using namespace std;

int cmmdc(int a, int b)
{
    if (!b)
        return a;
    return cmmdc(b, a%b);
}

int main()
{
    int t,a,b;
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>t;
    while (t)
    {
        f>>a;
        f>>b;
        g<<cmmdc(a,b)<<endl;
        t--;
    }
    return 0;
}
