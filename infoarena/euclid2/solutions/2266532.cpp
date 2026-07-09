#include <iostream>
#include <fstream>
using namespace std;
int gcd(int a,int b){
    if(!b)
        return a;
    return gcd(b,a%b);
}
int main()
{
    fstream f("cmmdc.in");
    ofstream g("cmmdc.out");
    int a,b;
    f>>a>>b;
    g<<gcd(a,b);
    f.close();
    g.close();
}
