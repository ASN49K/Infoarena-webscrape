#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
long a,b,c,i,r;
int main()
{
    f>>c;
    for(i=1;i<=c;i++)
    {
        f>>a>>b;
        r=a;
        while(r!=0)
        {
            r=a%b;
            a=b;
            b=r;
        }
        g<<a<<endl;
    }
}
