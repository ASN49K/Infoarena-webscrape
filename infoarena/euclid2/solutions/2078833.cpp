#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int a, b, n;

int main()
{
    f >> n;
    while(n--)
    {
        f >> a >> b;
        int r = a%b;
        while(r<0 or r>0)
        {
            a = b;
            b = r;
            r = (a%b);
        }

        g << b << endl;
    }
    return 0;
}
