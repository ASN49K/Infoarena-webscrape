#include <fstream>

using namespace std;

int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    int t,a,b;
    f>>t;
    if (1<=t && t<=100000)
        while(t>0)
        {
            f>>a;
            f>>b;
            if (a>=2 and b<=2*109)
                {while(a!=b)
                    {if(a>b)
                        a=a-b;
                    else
                        b=b-a;
                    }
                g<<a<<"\n";
                t=t-1;
                }
        }
    return 0;
}
