#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");

long long T,a,b,r;
int main()
{
    f >> T;
    for(int i=1; i<=T; i++)
    {
        f >> a >> b;
        while(b!=0)
        {
            r = a % b;
            a = b; b = r;
        }
        g << a << endl;
    }
    g.close();
    return 0;
}
