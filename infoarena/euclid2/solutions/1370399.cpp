#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int n,x,y,r,i,a,b;
int main()
{
    f>>n;
    for(i=1;i<=n;i++)
    {
        f>>a>>b;
        r=a%b;
        while(r!=0){a=b;b=r;r=a%b;}
        g<<b<<"/n";
    }
    return 0;
}
