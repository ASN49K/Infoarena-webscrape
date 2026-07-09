#include<fstream>
using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

long long n;
long long a,b;

void euclid()
{
    f>>n;
    for(long long i=0;i<n;i++)
    {

        f>>a>>b;
        long long r;
        while(b!=0)
        {
            r=b;
            b=a % b;
            a=r;

        }
        g<<a<<"\n";
    }
}
int main()
{
    euclid();
    return 0;
}
