#include <fstream>
#include <algorithm>

using namespace std;

int main()
{
    ifstream f("nim.in");
    ofstream g("nim.out");
    unsigned int t,nrp,x;
    f>>t;
    while (t--)
    {
        f>>nrp; unsigned int s=0;
        for (int i=1; i<=nrp; i++)
        {
            f>>x; s=s^x;
        }
        if (x) g<<'DA';
          else g<<'NU';
    }
    f.close(); g.close();
    return 0;
}
