#include <fstream>
#include <algorithm>

using namespace std;
ifstream f("euclid.in");
ofstream g("euclid.out");

unsigned gcd(unsigned,unsigned);

int main()
{
    int t;
    f>>t;

    while(t--){
        int a,b;
        f>>a>>b;
        g<<gcd(a,b)<<'\n';
    }


    return 0;
}

unsigned gcd(unsigned a,unsigned b)
{
    int r;
    if(b>a)
        swap(a,b);
    while(b){
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
