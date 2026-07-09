#include <fstream>
using namespace std;
int main()
{
long n,a,b,r;
ifstream f("euclid2.in");
ofstream o("euclid2.out");
f>>n;
while(n--)
     {
     f>>a>>b;
     while (b)
       {
       r=a%b;
       a=b;
       b=r;
       }
     o<<a<<"\n";
     }
return 0;
}