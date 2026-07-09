#include <fstream>

using namespace std;
ifstream f("euclid.in");
ofstream g("euclid.out");
int n,a,b,k,r;
int main()
{
    f>>n;
    for(k=1;k<=n;k++)
    {
        f>>a;f>>b;
        r=a%b;
        while(r!=0)
        {
            a=b;
            b=r;
            r=a%b;
        }
        g<<b<<endl;
    }
    return 0;
}
