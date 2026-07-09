#include<fstream>

using namespace std;

long gcd(long a, long b)
{
    if(!b)
        return a;
    return gcd(b, a%b);
}

int main()
{
ifstream f ("euclid2.in");
ofstream g ("euclid2.out");

long i, t, a, b, d;

f>>t;

for(i=1; i<=t; i++)
{
f>>a;
f>>b;
d=gcd(a, b);
g<<d<<endl;
}

f.close();
g.close();


return 0;
}
