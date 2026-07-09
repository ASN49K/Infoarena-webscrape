#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int a,b,r;
main()
{
    for(f>>a;f>>a>>b;)
    {
        for(;r=a%b;a=b,b=r);
        g<<b<<'\n';
    }
}
