#include <fstream>

using namespace std;
ifstream f("nim.in");
ofstream g("nim.out");

int t,n,x,y;

int main()
{
    f>>t;
    for(int i = 1; i <=t; ++i)
    {
        f>>n;
        f>>x;
        for(int j = 2; j <= n; ++j)
        {
            f>>y;
            x= x^y;
        }
        if(x == 0)
            g<< "NU\n";
        else g << "DA\n";
    }
    g.close();
    return 0;
}
