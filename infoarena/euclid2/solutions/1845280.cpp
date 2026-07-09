#include <fstream>
using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main()
{
    int n,a,b,c;
    f>>n;
    for(int i=1;i<=n;i++)
    {
        f>>a>>b;
        while(b!=0)
        {
            c=a%b;
            a=b;
            b=c;
        }
        g<<a<<"\n";
    }
    return 0;
}
