#include <iostream>
#include <fstream>

using namespace std;

int cmmdc(int a, int b)
{
    if((a==0) || (b==0))
        return a+b;
    if(a>b) return cmmdc(a%b,b);
    return cmmdc(a,b%a);
}

int main()
{
    long T,a,b;

    ifstream f("euclid2.in");
    ofstream g("euclid2.out");

    f>>T;
    for(int i=1;i<=T;i++)
    {
        f>>a>>b;
        g<<cmmdc(a,b)<<"\n";


    }
    f.close();
    g.close();
    return 0;
}
