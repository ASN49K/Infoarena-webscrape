#include<iostream>
#include<fstream>
using namespace std;
long cmmdc(long a,long b)
{
    long r;
    r=a%b;
    while(r!=0)
    {
    a=b;
    b=r;
    r=a%b;
    }
    return b;
}
int main ()
{
    long T,a,b;
    ifstream x("euclid2.in");
    ofstream y("euclid2.out");
    if(!x)
    return -1;
    if(!y)
    return -1;
    x>>T;
    for(long i=1;i<=T;i++)
    {
        x>>a>>b;
        y<<cmmdc(a,b);
    }
    x.close();
    y.close();
    return 0;
}

