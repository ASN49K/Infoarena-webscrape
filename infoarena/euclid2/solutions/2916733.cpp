#include <fstream>

using namespace std;

ifstream wi("euclid2.in");
ofstream wo("euclid2.out");

int cmmdc(int a, int b)
{
    while(b != 0)
    {
        int rest = a % b;
        a = b;
        b = rest;
    }

    return a;
}

int main()
{
    int t;
    wi >> t;
    for(int i = 1; i <= t; ++i)
    {
        int a, b;
        wi >> a >> b;
        wo << cmmdc(a, b) << "\n";
    }

    wi.close();
    wo.close();
    return 0;
}
