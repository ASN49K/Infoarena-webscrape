#include <iostream>
#include <fstream>
using namespace std;

long long cmmdc(long long a, long long b);

int main()
{
    int n,a,b;
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");
    in  >> n;
    for(int i=0;i<n;i++)
        {
            in >> a >>  b;
            out << cmmdc(a,b) << "\n";
        }
    return 0;
}


long long cmmdc(long long a, long long b)
{
    int t;
    while(b!=0)
    {
        t=b;
        b=a%b;
        a=t;
    }
    return a;
}
