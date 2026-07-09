#include <fstream>
using namespace std;

int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    long long int x, y, k, t;
    f>>t;
    while(t)
    {
        g>>x>>y;
        while(y!=0)
        {
            k=x%y;
            x=y;
            y=k;
        }
        g<<x<<'\n';
        t--;
    }
    f.close();
    g.close();
}
