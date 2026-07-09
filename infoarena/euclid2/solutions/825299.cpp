#include <fstream>

using namespace std;
int t,a,b,r;
int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>t;
    for(;t;t--)
    {
        f>>a>>b;
        for(;b;)
        {
            r=a%b;
            a=b;
            b=r;
        }
        g<<a<<endl;
    }
   return 0;
}
