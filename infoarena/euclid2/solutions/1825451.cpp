#include <iostream>
#include <fstream>
using namespace std;
int x,y,n,a,b;
int cmmdc(int a,int b)
{
    if(b==0)
        return a;
    else
        cmmdc(b,a%b);
}
int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>n;
    while(n)
    {
        f>>x>>y;
        g<<cmmdc(x,y)<<"\n";
        n--;
    }
}
