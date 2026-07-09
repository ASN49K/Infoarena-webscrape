#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main()
{
    int t,a,b;
    f>>t;
    while(t)
    {
        f>>a>>b;
        while(a && b)
        {
            if(a>b)
                a=a%b;
            else
                b=b%a;
        }
        if(b>a)
            g<<'\n'<<b;
        else
            g<<'\n'<<a;
        t--;
    }
    return 0;
}
