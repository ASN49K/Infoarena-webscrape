#include <fstream>
using namespace std;
int n, t, a, s;
int main()
{
    ifstream f("nim.in");
    ofstream g("nim.out");
    f >> t;
    for(int i = 0; i < t; ++i)
    {
        f >> n;
        s = 0;
        for(int k = 0; k < n; ++k)
        {
            f >> a;
            s ^= a;
        }
        if(s)
            g << "DA\n";
        else
            g << "NU\n";
    }
    f.close();
    g.close();
}
