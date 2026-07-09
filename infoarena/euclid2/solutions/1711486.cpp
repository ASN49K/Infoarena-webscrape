#include <fstream>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int a,b,d;
int main()
{
    f>>a>>b;
    while(b)
    {  d=a%b;
       a=b;
       b=d;
    }
    g<<a;
g.close(); return 0;
}
