#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

unsigned long n;
unsigned long long a,b;

unsigned long long cmmdc(unsigned long long a, unsigned long long b){
if(!b) return a;
else return cmmdc(b, a%b);
}

int main()
{
    f>>n;
    for(unsigned long i=1;i<=n;i++)
    {
        f>>a>>b;
       if(b>a) swap(a,b);
        g<<cmmdc(a,b)<<"\n";
    }
    return 0;
}
