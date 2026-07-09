#include <fstream>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int t,a,b,i,c,r;

int main()
{
    f >> t;
    for (i=1;i<=t;i++)
    {
        f >> a >> b;
        r=a%b;
        if(r==0)
            g << b << "\n";
        else
        {
            while(r!=0)
            {
                r=a%b;
                a=b;
                b=r;
            }
            g << a << "\n";
        }
    }
    return 0;
}
