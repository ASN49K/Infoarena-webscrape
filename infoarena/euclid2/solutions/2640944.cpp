#include <fstream>

using namespace std;
long long t,n,m,r;
int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>t;
    while(t)
    {
        t--;
        f>>n>>m;
        r=0;
        while(m)
        {
            r=n%m;
            n=m;
            m=r;
        }
        g<<n<<'\n';
    }
    f.close(); g.close();
    return 0;
}
