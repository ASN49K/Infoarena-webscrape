#include<fstream>
using namespace std;
int a,b,t,r,i;
int main ()
{
    ifstream f("euclid.in");
    ofstream g("euclid.out");
    f>>a>>b>>t;
   while(b)
    {r=a%b;
    a=b;
    b=r;
    g<<a;
   }
return 0;
}
