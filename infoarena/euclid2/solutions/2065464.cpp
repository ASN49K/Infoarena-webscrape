#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");

int divide(int a,int b)
{
    if(a*b==0)
        return a+b;
if(a>b)
    return divide(a%b,b);
return divide(a,b%a);
}
int main()
{
     int c,d,n;
     f>>n;
     for(int i=1;i<=n;i++)
     {
         f>>c>>d;
         g<<divide(c,d)<<endl;
     }
     f.close();
     g.close();
    return 0;
}
