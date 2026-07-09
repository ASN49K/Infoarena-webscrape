#include <fstream>

using namespace std;

int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    int t,a,b;
    f>>t;
    if(t==t)
        {f>>a;
        f>>b;
        while(a!=b)
            {if(a>b)
                a=a-b;
            else
                b=b-a;
            }
        g<<a;
        }
    while(t-1>0)
    {
        f>>a;
        f>>b;
        while(a!=b)
            {if(a>b)
                a=a-b;
            else
                b=b-a;
            }
        g<<"\n"<<a;
        t=t-1;
    }
    return 0;
}
