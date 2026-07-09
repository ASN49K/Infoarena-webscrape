#include <iostream>
#include <fstream>
using namespace std;
ifstream fcin("euclid2.in");
ofstream fcout("euclid2.out");
int n, a, b, r, i;
int main()
{
    fcin>>n;
    for(i=1; i<=n; i++)
    {
        fcin>>a>>b;
        while(b!=0)
        {
            r=a%b;
            a=b;
            b=r;
        }
        fcout<<a<<endl;
    }
    return 0;
}
