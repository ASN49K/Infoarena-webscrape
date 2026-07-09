#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int main()
{
    int n,a,b;
    f>>n;
    for(int i = 1; i<=n; i++)
    {
        f>>a>>b;
    while(b!=0)
    {
        int r = a%b;
        a = b;
        b = r;
    }
    g<<a<<'\n';
    }

    return 0;
}
