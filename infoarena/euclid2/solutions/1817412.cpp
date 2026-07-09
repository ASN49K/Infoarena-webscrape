#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
long a,b,c;
long euc(long a,long b)
{
    if(b==0)
        return a;
    else
        return euc(b,a%b);
}
int main()
{
    f>>c;
    while(c!=0)
    {
        f>>a>>b;
        g<<euc(a,b)<<endl;
        c--;
    }
}
