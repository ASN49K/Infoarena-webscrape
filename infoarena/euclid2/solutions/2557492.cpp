#include <fstream>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");

int main()
{
    int n,a,b,r;
    f>>n;
    while(n--)
    {
        f>>a>>b;
        do
        {
            r=a%b;
            a=b;
            b=r;
        }while(b);
        g<<a<<'\n';
    }
    f.close();
    g.close();
    return 0;
}
