#include <iostream>
#include <fstream>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");

int cmmdc(long int a,long int b)
{
    long int r=0;
    
    while (b!=0)
    {
        r = a % b;
        a=b;
        b=r;    
    }
    return a;  
}
int main()
{
    int nr;
    f>>nr;
    long int x,y;
    while (nr--)
    {
        f>>x,f>>y;
        g<<cmmdc(x,y)<<endl;
    }
    
 return 0;
}
