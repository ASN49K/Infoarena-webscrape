#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

long int T;
long long int a,b;

long long cmmdc(long long x,long long y)
{
    if(x%y==0)
     return y;
    else
     return cmmdc(y,(x%y));
}

int main()
{
    long int i;
    f>>T;
    for(i=1;i<=T;i++){
     f>>a>>b;
     g<<cmmdc(a,b)<<endl;
    }
    f.close();
    g.close();
    return 0;
}
