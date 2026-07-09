#include <iostream>
#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int gcd(int a,int b)
{
    if(b==0)
        return a;
    if(a==0)
        return b;
    if(a==b)
        return a;
    while(a!=b)
        if(a>b)
            a=a-b;
        else
            b=b-a;
    return a;
}
int main()
{
    int t,a,b;
    f>>t;
    while(f>>a>>b)
        g<<gcd(a,b)<<endl;
    return 0;
}
