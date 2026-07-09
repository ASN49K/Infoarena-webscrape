#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
long long n,a,b,r,i;
int main()
{
    f>>n;
    for(i=1;i<=n;i++)
        {
            f>>a>>b;
          do
        {
          r=a%b;
          a=b;
          b=r;
        }
        while (r>0);
        g<<a<<endl;
        }

    return 0;
}
