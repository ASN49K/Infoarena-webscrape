#include <fstream>

using namespace std;

int cmmdc(int a, int b)
{
    if(b != 0)
        return cmmdc(b, a%b);
    return a;
}

int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    int n, a, b;
    f >> n;
    for(int i = 1; i <= n; i++)
    {
        f >> a >> b;
        g << cmmdc(a, b) << "\n";
    }
    return 0;
}
