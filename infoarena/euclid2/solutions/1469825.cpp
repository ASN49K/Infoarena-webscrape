#include <iostream>
#include <fstream>
 
using namespace std;
 
int T, a, b;
 
int cmmdc(int a, int b)
{
    if (!b) return a;
    return cmmdc(b, a%b);
}
 
int main()
{
    ifstream fi("euclid2.in");
    ofstream fo("euclid2.out");
     
    fi>>T;
    for (T;T;--T)
    {
        fi>>a>>b;
        fo<<cmmdc(a,b)<<"\n";
    }
    return (0);
 
}
