#include <fstream>
using namespace std;
ifstream f ("euclid2.in");
ofstream g ("euclid2.out");
int n,a,b;
int main()
{
    int i,r;
    f>>n;
    for(i=1;i<=n;i++)
    {
       f>>a>>b;
       while(b)
       {
        r=a%b;
        a=b;
        b=r;
       }
       g<<a<<'\n';
    }
    return 0;
}
