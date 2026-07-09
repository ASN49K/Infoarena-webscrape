#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
/*int Euclid(int a, int b)
{
    int rest;
    while(b)
    {
        rest=a%b;
        a=b;
        b=rest;
    }
    return a;
}

int Euclid2_0(int a, int b)
{
    if(!b) return a;
    if(a>b) return Euclid2_0(a-b,b);
    return Euclid2_0(a, b-a);
}*/
int a, b, T;
int Euclid3_0(int a, int b)
{
    if(!b) return a;
    return Euclid3_0(b,a%b);
}
int main()
{
    f>>T;
    while(T)
    {
        f>>a>>b;
        g<<Euclid3_0(a,b)<<endl;
        T--;
    }
    return 0;
}
