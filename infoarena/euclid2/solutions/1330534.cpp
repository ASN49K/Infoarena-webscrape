#include <iostream>
#include <fstream>

using namespace std;

long long cmmdc(long long a, long long b)
{
    long long r;
    while(b>0)
    {
        r=b;
        b=a%b;
        a=r;
    }
    return a;
}

int main()
{
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");
    int n,a,b;
    in >> n;
    for(int i=0;i<n;i++)
    {
        in >> a >> b;
        out << cmmdc(a,b)<< "\n";
    }
    return 0;
}
