#include <fstream>
using namespace std;
ifstream f("nim.in");
ofstream g("nim.out");

int main()
{
    int t, n, r, a;
    f>>t;
    while (t--)
    {
        f>>n;
        r=0;
        while (n--)
        {
            f>>a;
            r^=a;
        }
        if (r==0) g<<"NU"<<'\n';
        else g<<"DA"<<'\n';
    }


    return 0;
}
