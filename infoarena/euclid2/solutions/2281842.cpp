#include <iostream>
#include <fstream>
using namespace std;
int euclid(int a,int b)
{
    int c;
    while(b!=0)
    {
        c=b;
        b=a%b;
        a=c;
    }
    return a;
}
int gcd(int a,int b)
{
    if(!b)
        return a;
    return gcd(b,a%b);
}
int main()
{
    int T,a,b;
    ifstream f("euclid2.in");
    ofstream g("euclid2.out",ios::app);
    f>>T;
    for (int i=0;i<T;i++)
    {
        f>>a>>b;
        g<<euclid(a,b)<<endl;

    }
    return 0;
}
