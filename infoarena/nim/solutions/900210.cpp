#include <fstream>
#include <algorithm>

using namespace std;

ifstream f("nim.in");
ofstream g("nim.out");

int main()
{
    unsigned int t,nrp,x;
    f>>t;
    while (t--)
    {
        f>>nrp; unsigned int s=0;
        for (int i=1; i<=nrp; i++)
        {
            f>>x; s=s^x;
        }
        if (x) g<<'DA\n';
          else g<<'NU\n';
    }
    f.close(); g.close();
    return 0;
}
