#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");


int main()
{
    long long a,b,n,r,i,csere;
    f>>n;
    for(i=1;i<=n;i++)
    {
        f>>a>>b;
        if(a<b) {csere=a;a=b;b=csere;}
        r=a%b;
        while(r)
        {
            a=b;
            b=r;
            r=a%b;
        }
        g<<b<<"\n";
    }
    return 0;
}
