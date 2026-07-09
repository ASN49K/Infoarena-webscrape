
#include <iostream>
#include <fstream>
using namespace std;

int main()
{int r, T, a, b, i;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
f>>T;

for(i=1; i<=T; i++)
    {f>>a;
    f>>b;
    while(a%b!=0)
        {r=a%b;
        a=b;
        b=r;
        }
    g<<b<<endl;
    }
    f.close();
    g.close();

    return 0;
}
