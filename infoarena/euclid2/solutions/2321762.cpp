#include <iostream>
#include <fstream>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
int euclid(int a, int b)
{
    int r;
    r=a%b;
    while (b)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}
int n,a,b,i,r;
int main()
{
    in>>n;
    for(i=1; i<=n; i++)
    {
        in>>a>>b;
        while (b)
        {
            r = a % b;
            a = b;
            b = r;
        }
    out<<a<<endl;
    }
    return 0;
}
