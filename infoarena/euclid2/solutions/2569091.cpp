#include <fstream>

using namespace std;
ifstream fi("euclid2.in");
ofstream fo("euclid2.out");
int t,a,b,r;
int main()
{
    fi>>t;
    while(t--)
    {
        fi>>a>>b;
        while(b!=0)
        {
            r=a%b;
            a=b;
            b=r;
        }
        fo<<a<<"\n";
    }
    fi.close();
    fo.close();
    return 0;
}
