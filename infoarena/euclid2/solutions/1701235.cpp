#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int a,b,m,T,i;
int main()
{
    f>>T;
    for(i=1;i<=T;i++)
    {
    f>>a;
    f>>b;
while(b!=0)
{
    m=a%b;
    a=b;
    b=m;
}
g<<a<<'\n';
}
}
