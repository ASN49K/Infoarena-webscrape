#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");

int main()
{int T,i;
 long r,a,b;
 f>>T;
 for(i=1;i<=T;i++)
    {f>>a>>b;
    while(b)
    {r=a%b;
     a=b;
     b=r;}
    g<<a<<'\n';}
 return 0;}
