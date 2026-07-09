#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");

/*
int cmmdc(int a,int b)
{
    int c=a%b;
    while(c!=0)
    {
        a=b;
        b=c;
        c=a%b;
    }
    return b;
}

/// cmmdc(a, b) = cmmdc(b, a % b)

/// cmmdc(a, 0) = a

int cmmdc(int a, int b) {
    if(b == 0)
        return a;
    return cmmdc(b, a % b);
}
*/

/// __gcd(x, y)


int main()
{
    int n;
    in>>n;
    int a,b;
    for(int i=1;i<=n;i++)
    {
        in>>a>>b;
        out<< __gcd(a,b)<<'\n';
    }

    return 0;
}
