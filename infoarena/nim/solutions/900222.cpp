#include <fstream>
#include <algorithm>

using namespace std;

ifstream f("nim.in");
ofstream g("nim.out");

int main()
{
    int t,nrp,x;
    f>>t;
    while (t--)
    {
        f>>nrp;
        int s=0;
        for (int j=1; j<=nrp; ++j)
        {
            f>>x;
            s=s^x;
        }
        if (s) g<<'DA\n';
          else g<<'NU\n';
    }
    f.close(); g.close();
    return 0;
}
