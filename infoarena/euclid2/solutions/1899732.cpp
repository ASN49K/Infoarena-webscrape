#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int i,a,b,n;
int main ()
{
    f>>n;
    for(i=1;i<=n;i++)
    {
        f>>a>>b;
        while(b)
        {
            int r=a%b;
            a=b;
            b=r;
        }
        g<<a<<'\n';
    }
    return 0;
}
