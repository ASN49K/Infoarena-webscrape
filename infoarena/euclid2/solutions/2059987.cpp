#include <fstream>
ifstream f("euclid2.in");
ofstream g("euclid2.out");
using namespace std;
int a,b,t,i;
int T;
int main()

{f>>T;
for(i=1;i<=T;i++)
{f>>a>>b;

    while (b != 0)
    {
        t = b;
        b = a % b;
        a = t;
    }
    g<<a<<'\n';
}
    return 0;
}
