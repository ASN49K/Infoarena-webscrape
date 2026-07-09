#include<fstream>
#include<stdlib.h>
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
//ofstream g ("euclid2.out");
FILE *g=fopen("euclid2.out", "w");
long i, t, a, b, d;

f>>t;

for(i=1; i<=t; i++)
{
f>>a;
f>>b;
d=gcd(a, b);
fprintf(g, "%d\n", d);
//g<<d<<endl;
}

f.close();
fclose(g);//g.close();


return 0;
}
