#include <fstream.h>
#include <iostream.h>
int euclid (int a,int b)
    {
    int r;
    while(b)
     {
     r=a%b;
     a=b;
     b=r;
     }
    return a;
    }
    
int main(void)
{
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int a,b,t;
f>>t;
while (t)
    {
    f>>a>>b;
    a=euclid(a,b);
    g<<a<<endl;
    t--;
    }
f.close();
g.close();
return 0;
}
