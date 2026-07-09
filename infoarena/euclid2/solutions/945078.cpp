#include <fstream>
using namespace std;
int main()
{
    int a,b,r,t;

    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>t;
    while(t)
    {
        f>>a>>b;
        while(b)
        {
            r=a%b;
            a=b;
            b=r;
        }
        t--;
        g<<a<<endl;
    }
}
