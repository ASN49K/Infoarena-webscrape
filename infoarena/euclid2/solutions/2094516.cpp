#include <fstream>
using namespace std;
long long T,a,b,i,r;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main()
{
    f>>T;
    for(i=1;i<=T;i++)
    {
        f>>a>>b;
        r=a%b;
        while(r!=0)
        {
            a=b;
            b=r;
            r=a%b;
        }
        g<<b;
        g<<endl;
    }
    return 0;

}
