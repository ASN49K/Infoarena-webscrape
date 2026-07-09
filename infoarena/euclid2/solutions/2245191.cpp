#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int a,b,r;
int main()
{   f>>a>>b;
    while(b)
    {   r=a%b;
        a=b;
        b=r;
    }
    g<<a;
    return 0;
}
