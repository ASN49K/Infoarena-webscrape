#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");
int t,a,b,i;
int main()
{
    f>>t;
    for(i=1;i<=t;i++)
    {
        f>>a>>b;
        while(a!=0 && b!=0)
        {
            if(a<b)
                b=b-a;
            else
                a=a-b;
        }
        if(a==0)
            g<<b<<'\n';
        else
            g<<a<<'\n';
    }
    return 0;
}
