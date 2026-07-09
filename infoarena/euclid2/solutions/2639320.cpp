#include <iostream>
#include <fstream>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");

long int  cmmdc(long int a,long int b)
{
    if(b)
        return cmmdc(a,b);
    else
    {
        return a;
    }
     
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
