#include <iostream>
#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int gcd(int a,int b)
{
    if (b == 0)
       return a;
    else
       return gcd(b,a%b);
}
int main()
{
    int t,a,b;
    f>>t;
    while(f>>a>>b)
        g<<gcd(a,b)<<endl;
    return 0;
}
