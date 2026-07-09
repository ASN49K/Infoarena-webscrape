#include <fstream>

using namespace std;

int main()
{ifstream f ("euclid2.in");
ofstream g  ("euclid2.out");
long a,b,t,i,r;
f>>t;

for (i=1;i<=t;i++)
{
    f>>a>>b;
while (b != 0)
    {
        r = b;
        b = a % b;
        a = r;
    }
g<<a<<"\n";
}

    f.close();
    g.close();
}
