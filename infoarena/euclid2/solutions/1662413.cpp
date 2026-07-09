#include <iostream>
#include <fstream>
using namespace std;
int n,c,t,a,b,r;
int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>t;
    for(int i=1;i<=t;i++)
    {
        f>>a>>b;
        if(a<b) {c=a; a=b; b=c;}
        r=a%b;
        while(r!=0) {a=b;b=r;r=a%b;}
        g<<b<<"\n";
    }
    return 0;
    f.close();g.close();
}
