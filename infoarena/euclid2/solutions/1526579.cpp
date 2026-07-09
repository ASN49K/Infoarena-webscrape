#include <iostream>
#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main()
{
    int n,a,b,i,x;
    f>>n;
    for(i=1;i<=n;i++)
    {
        f>>a>>b;
        while(a!=0)

        {
            if(a>b && b!=0)
                a=a%b;
            else
            {
                x=a;
                a=b;
                b=x;
                a=a%b;
            }
            if(a==0)
                g<<b<<'\n';
        }
    }
    return 0;
}
