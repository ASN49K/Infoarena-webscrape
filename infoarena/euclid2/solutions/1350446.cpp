#include <iostream>
#include <fstream>
using namespace std;

ifstream in ("euclid2.in");
ofstream out ("euclid2.out");

int a,b,i,n;

int gcd(int a, int b)
{
    if (b==0) return a;
    return gcd(b, a % b);
}

int main()
{
    in>>n;
    for(i=1;i<=n;i++){
        in>>a>>b;
        out<<gcd(a,b)<<endl;
    }
    return 0;
}
