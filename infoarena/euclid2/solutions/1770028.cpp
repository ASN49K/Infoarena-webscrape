#include <iostream>
#include <fstream>
using namespace std;
unsigned div(unsigned a,unsigned b)
{
    while(a!=b)
        if(a>b)
            a=a-b;
        else
            b=b-a;
    return a;
}
int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    unsigned T,i,a,b;
    f>>T;
    for(i=1;i<=T;i++)
        {
        f>>a>>b;
        g<<div(a,b)<<'\n';
        }
    return 0;
}
