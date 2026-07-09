#include <iostream>
#include <fstream>

using namespace std;
ifstream f ("euclid2.in");
ofstream g ("euclid2.out");
int cmmdc(int a, int b)
{
    if(b==0) return a;
    else cmmdc(b, a%b);
}
int main()
{ int t;
f>>t;
for(int i=0;i<t;i++)
{ int a,b;
    f>>a>>b;
    g<<cmmdc(a,b)<<'\n';
}

    return 0;
}
