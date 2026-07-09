#include <fstream>
using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int n,a,b,i,r;
int main()
{
    f>>n;
    for(i=1;i<=n;++i)
    {
        f>>a>>b;
//        while(a!=b)
//            if (a>b) a=a-b;
//                else b=b-a;
        while(b>0)
        {
            r=a%b;
            a=b;
            b=r;
        }
        g<<a<<"\n";
    }
    return 0;
}
