#include <iostream>
#include <fstream>

using namespace std;

ifstream q("euclid2.in");
ofstream w("euclid2.out");

int main()
{int n,a,b,i,r;

    q>>n;
    for(i=1;i<=n;i++)
    {
        q>>a>>b;
        while(b)
        {
            r=a%b;
            a=b;
            b=r;
        }
        w<<a<<"\n";
    }
    return 0;
}
