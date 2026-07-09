#include <fstream>

using namespace std;
int a,b,r;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main()
{f>>a>>b;
r=-1;
while(r!=0)
{
    r=a%b;
    a=b;
    b=r;
}
g<<b;
    return 0;
}
