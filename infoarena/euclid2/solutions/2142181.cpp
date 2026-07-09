#include <iostream>
#include<fstream>

using namespace std;

ifstream f("euclid.in");
ofstream g("euclid.out");

int n,i,a,b,r;

int main()
{

    f>>n;
    for(i=1;i<=n;i++)
    {
        f>>a>>b;
        r=a%b;
        while(r)
        {
            a=b;
            b=r;
            r=a%b;
        }
        g<<b<<endl;
    }


}
