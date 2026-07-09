#include <iostream>
#include <fstream>
using namespace std;
ifstream f ("euclid2.in");
ofstream g ("euclid2.out");
int main()
{
    long long int x,y,i;
    int T,ok;
    f>>T;
    while (T!=0)
    {
        f>>x>>y;
        ok=1;
        if (x>y)
        {
            for (i=y; i>=1&&ok==1; i--)
                if (y%i==0 && x%i==0)
                {
                    g<<i<<endl;
                    ok=0;
                }
        }
        else
            for (i=x; i>=1&&ok==1; i--)
                if (x%i==0 && y%i==0)
                {
                    g<<i<<endl;
                    ok=0;
                }
        T--;
    }
    return 0;
}
