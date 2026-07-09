#include <fstream.h>
#include <iostream.h>
int gcd(int a, int b)   
{   
    if (!b) return a;   
    return gcd(b, a % b);   
}   
    
int main(void)
{
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int a,b,i,t;
f>>t;
for (i=0;i<t;i++)
    {
    f>>a>>b;
    g<<gcd(a,b)<<endl;
    }
f.close();
g.close();
return 0;
}
