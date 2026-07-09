#include <fstream>
using namespace std;
int main()
{
int n,a,b,r;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
f>>n;
while (n!=0)
{
f>>a;
f>>b;
r=a%b;
    while (r!=0)
    {
    a=b;
    b=r;
    r=a%b;
    }
g<<b<<endl;
n--;
}
return 0;
}
