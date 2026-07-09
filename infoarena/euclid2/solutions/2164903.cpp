#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");

int T,a,b;

int euclid(int a, int b)
    {
        if(!b) return a;
        return euclid(b, a%b);
    }
int main()
{
    f>>T;
    for(int i=T; i>=1; i--)
        {f>>a>>b;
         g<<euclid(a,b)<<endl;
    }
}
