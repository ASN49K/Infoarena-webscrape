#include <fstream>
using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");
int i,n,a,b,r;
int euclid(int a, int b)
{
    while(b>0)
 {
    r=a%b;
    a=b;
    b=r;
}
    return a;
}
int main()
{

f>>n;
for(i=0;i<n;i++)
{f>>a>>b;

g<<euclid(a,b)<<endl;
}
f.close();
g.close();
return 0;
}
