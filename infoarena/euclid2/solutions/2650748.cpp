#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int a,b,c,n,i;

int main()
{
    f>>n;

    for(i=1;i<=n;i++)
    {
        f>>a>>b;

        if(b>a)
        {
            while (a>0)
            {
                c=b%a;
                b=a;
                a=c;
            }

            g<<b<<"\n";
        }

        else
        {
            while (b>0)
            {
                c=a%b;
                a=b;
                b=c;

            }
            g<<a<<"\n";
        }

    }


    return 0;
}
