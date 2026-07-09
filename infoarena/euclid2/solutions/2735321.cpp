
#include <fstream>
using namespace std;

int main()
{long int r, t, a, b;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
f>>t;

while(t!=0)
    {f>>a;
    f>>b;
    while(b!=0)
        {r=a%b;
        a=b;
        b=r;
        }
    g<<b<<'\n';
    t--;
    }
    f.close();
    g.close();

    return 0;
}
