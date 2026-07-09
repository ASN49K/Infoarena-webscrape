#include <iostream>
#include <fstream>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int cmmdc(int a,int b)
{
    while(a*b!=0)
    {
         if(a>b)
         a=a%b;
         else
         b=b%a;
    }
    return a+b;
}
int main()
{
    int a,b,T;
    f>>T;
    while(T)
    {
        f>>a;f>>b;
        g<<cmmdc(a,b)<<endl;
        T--;
    }
    f.close();
    g.close();
}
