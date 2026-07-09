#include <iostream>
#include <fstream>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");

int cmmdc(double a,double b)
{
    double r=0;
    
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
    double x,y;
    for(int i=0;i<nr;i++)
        {
            f>>x,f>>y;
            g<<cmmdc(x,y)<<endl;
        }
 return 0;
}
