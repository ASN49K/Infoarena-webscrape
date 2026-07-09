#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ifstream f ("euclid2.in");
    ofstream g ("euclid2.out");
    int a,b,t,c,i;
    f>>t;
    for(i=1;i<=t;i++)
    {
        f>>a;
        f>>b;
        c=min(a,b);
        for(i=2;i<=c;i++)
        {
            if((a%i==0)&&(b%i==0))g<<i<<"\n";
        }
    }
    return 0;
}
