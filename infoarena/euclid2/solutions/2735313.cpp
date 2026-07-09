
#include <iostream>
#include <fstream>
using namespace std;

int main()
{int r, t, a, b, i;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
f>>t;

while(t!=0)
    {f>>a;
    f>>b;
    while(a%b!=0)
        {r=a%b;
        a=b;
        b=r;
        }
    g<<b<<endl;
    t--;
    }
    f.close();
    g.close();

    return 0;
}
