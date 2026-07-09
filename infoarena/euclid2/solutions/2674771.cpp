#include <fstream>

using namespace std;
int cgd(int a, int b)
{

    if (!b) return a;
    return cgd(b, a % b);
}


int main()
{
    ifstream f ("euclid2.in");
    ofstream g ("euclid2.out");
    int a, b, n;
    f>>n;
    for(n;n;--n)
    {
        f>>a>>b;
        g<<cgd(a,b)<<'\n';

    }



}