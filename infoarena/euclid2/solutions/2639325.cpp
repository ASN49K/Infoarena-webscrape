#include <iostream>
#include <fstream>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");

int cmmdc(int a,int b)
{
    if(b)
        return cmmdc(b,a%b);
    else
    {
        return a;
    }
     
}
int main()
{
    int nr;
    f>>nr;
    int x,y;
    while (nr--)
    {
        f>>x>>y;
        g<<cmmdc(x,y)<<'\n';
    }
    
 return 0;
}

