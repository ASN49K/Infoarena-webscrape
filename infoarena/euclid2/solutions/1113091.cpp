
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int  n,a,b,aux,r;

int main()
{
    f>>n;
    for(long int i=1;i<=n;i++)
    {
        f>>a>>b;
        if(a&&b!=0)
        {
            r=a%b;
            while(r!=0)
            {
                a=b;
                b=r;
                r=a%b;
            }

        }
        g<<b<<endl;
    }

    return 0;
}
