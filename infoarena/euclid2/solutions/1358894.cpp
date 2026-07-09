#include <fstream>

using namespace std;

int main()
{
    int T,a,b,i,r;
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>T;
    for(i=1;i<=T;i++)
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
    f.close();
    g.close();
    return 0;
}
