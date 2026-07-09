#include <fstream>
#include <algorithm>

using namespace std;

ifstream f("nim.in");
ofstream g("nim.out");

int main()
{
    int t,n,x;
    f>>t;
    for (int i=1; i<=t; ++i)
    {
        f>>n;
        int s=0;
        for (int j=1; j<=n; ++j)
        {
            f>>x;
            s=s^x;
        }
     if (s==0) g<<"NU\n";
          else g<<"DA\n";
    }
    f.close(); g.close();
    return 0;
}
