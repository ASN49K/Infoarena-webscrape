#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");

int T,a,b;

int main()
{   f>>T;
    while(T)
    {   f>>a>>b; int r=0;
        while(b)
        {   r=a%b; a=b; b=r;
        }
        g<<a<<'\n';
        T--;
    }
g.close();
return 0;
}
