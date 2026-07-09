#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int cmmdc(int a, int b)
{
    int r;
    while (b>0){
        r=a%b;
        a=b;
        b=r;}
    g<<a<<endl;
}
int main()
{
    int i,r,a,b,T;
    f>>T;
    for(i=0;i<T;i++)
    {
        f>>a; f>>b;
        cmmdc(a,b);
    }
    return 0;
}
