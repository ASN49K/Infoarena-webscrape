#include <iostream>
#include <fstream>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
int gcd(int a,int b)
{
    int r=a%b;
    if(r==0)
        return b;
    return gcd(b,r);
}
int main()
{
    int n;
    in>>n;
    for(int i=1; i<=n; i++)
    {
        int a,b;
        in>>a>>b;
        out<<gcd(a,b);
    }
    return 0;
}
