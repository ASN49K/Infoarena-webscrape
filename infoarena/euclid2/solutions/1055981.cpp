#include <fstream>

using namespace std;
ifstream f ("euclid2.in");
ofstream g ("euclid2.out");
int a,b,t,r1;

int main()
{
    f>>t;
    for(;t;t--)
    {
        f>>a>>b;
        for(;b;)
        {
            r1=a%b;
            a=b;
            b=r1;
        }
        g<<a<<endl;
    }


    return 0;
}
