#include <iostream>
#include <fstream>
using namespace std;
int n,c,t,a,b;
int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>t;
    for(int i=1;i<=t;i++)
        {
            f>>a;
            f>>b;
        }
    for(int i=1;i<=t;i++)
        {
            while(b!=0)
        {
            c=a%b;
            a=b;
            b=c;
        }
        g<<a<<"\n";
        }
    return 0;
}
