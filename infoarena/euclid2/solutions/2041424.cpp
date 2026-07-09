#include <iostream>
#include <fstream>
using namespace std;
ifstream f ("euclid2.in");
ofstream g ("euclid2.out");
int main()
{
    long long int x,y,i;
    int T,ok,r;
    f>>T;
    while (T!=0)
    {
        f>>x>>y;
        r=x%y;
        while (r!=0)
        {
            x=y;
            y=r;
            r=x%y;
        }
        g<<y<<endl;
        T--;
    }
    return 0;
}
