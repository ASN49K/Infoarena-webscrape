#include <fstream>

using namespace std;

int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    unsigned int a, b, i, t, r;
    f>>t;
    for(i=1;i<=t;i++)
    {
        f>>a>>b;
        if(a>b)
        {
            r=a;
            a=b;
            b=r;
        }
        while(b%a!=0)
        {
            r=b%a;
            b=a;
            a=r;
        }
        g<<a<<endl;
    }
    return 0;
}
