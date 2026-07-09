#include <fstream>

using namespace std;
int t,a,b,r;
int main()
{
    ifstream f("euclid.in");
    ofstream g("euclid.out");
    f>>t;
    while(t)
    {
        f>>a>>b;
        while(b)
        {
            r=a%b;
            a=b;
            b=r;
        }
        g<<a<<'\n';
    }
    f.close(); g.close();
    return 0;
}
