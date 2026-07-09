#include <fstream>

using namespace std;

int t,A,B;

int cmmdc(int a, int b)
{
    if (!b)
        return a;
    return cmmdc(b, a%b);
}

int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>t;
    while (t)
    {
        t--;
        f>>A;
        f>>B;
        g<<cmmdc(A,B)<<endl;
    }
    return 0;
}
