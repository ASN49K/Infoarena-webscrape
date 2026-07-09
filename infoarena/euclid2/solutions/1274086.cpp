#include <fstream>

using namespace std;

int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    int t,a,b;
    f>>t;
    while(t>0)
    {
        f>>a;
        f>>b;
        while(a!=b)
            {if(a>b)
                a=a-b;
            else
                b=b-a;
            }
        g<<a<<"\n";
        t=t-1;
    }
    return 0;
}
