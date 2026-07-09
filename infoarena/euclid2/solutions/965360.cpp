#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
unsigned long long t,a,b,r;
/*//recursiv vine:
int cmmdc(int a , int b)
{   if(!b) return a;
    return cmmdc(b,a%b);
}
*/
int main()
{f>>t;
 while (t--)
 {
    f>>a>>b;
  r=a%b;
    while (r)
    {  a=b;
    b=r;
    r=a%b;
           }
g<<b<<'\n';    }
    return 0;
}
