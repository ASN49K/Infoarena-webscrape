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
int a[100000],b[100000],r,i,t;
f>>t;
for (i=0;i<t;i++)
    f>>a[i]>>b[i];
f.close();
for (i=0;i<t;i++)
    g<<gcd(a[i],b[i])<<endl;
g.close();
return 0;
}
