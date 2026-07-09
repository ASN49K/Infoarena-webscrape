#include <fstream>

using namespace std;

int main()
{
    int a,T,b,c,i;
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>T;
    for(i=1;i<=T;i++)
    {
        f>>a;
        f>>b;
        while (b!=0)
        {
            c = a % b;
            a = b;
            b = c;
        }
        g<<a<<endl;
    }
    return 0;
}
