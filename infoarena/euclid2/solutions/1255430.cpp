#include <iostream>
#include<fstream>

using namespace std;
ifstream f("euclid.in");
ofstream g("euclid2.out");
int cmmdc(int a,int b)
{
    int r=a%b;
    if(!r)
        return b;
    else
        return cmmdc(b,r);

}
int main()
{
    int n,a,b;
    f>>n;
    while(n--)
    {
        f>>a>>b;
        g<<cmmdc(a,b)<<"\n";
    }
    float c;
    c=11111111111111111111;

}
