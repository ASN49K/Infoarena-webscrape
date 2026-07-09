#include <iostream>
#include<fstream>
using namespace std;
int a,b,x,i,y,r,n;
int main()
{
    ifstream f("euclid2.in")
    f>>n;
    ofstream g("euclid2.out");
    for(i=0;i<n;++i)
    {
        f>>a>>b;
        r=a%b;
        while(r)
        {
            a=b;b=r;r=a%b;
        }
        g<<b<<'\n';
    }
    return 0;
}
