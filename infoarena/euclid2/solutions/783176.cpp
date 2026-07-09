#include <iostream>
#include <fstream>
using namespace std;
ifstream f ("euclid2.in");
ofstream g ("euclid2.out");
int main ()
{
    int n, a, b, c, i;
    f>>n;
    for (i=1; i<=n; i++)
    {
        f>>a>>b;
        while (b)
        {
            c=a%b;
            a=b;
            b=c;
        }
        g<<a<<endl;
    }
    return 0;
}
