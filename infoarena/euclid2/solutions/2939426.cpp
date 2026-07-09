#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
unsigned int T, a, b, r, i;

int main()
{
    f>>T;
    for(i=1; i<=T; i++){
        f>>a>>b;
        if(a!=0 && b!=0)
        {
            while(b!=0)
            {
                r = a%b;
                a = b;
                b = r;
            }
        g<<a<<"\n";
        }
        else g<<"0\n";
    }
    return 0;
}
