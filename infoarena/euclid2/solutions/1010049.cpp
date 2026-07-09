#include<fstream>
using namespace std;
int a,b,t,r,i;
int main ()
{
    ifstream f("euclid.in");
    ofstream g("euclid.out");
    f>>a>>b>>t;
    for(i==1;i<=t;i++)
    r=a%b;
    a=b;
    b=r;
    g<<a;
return 0;
}
