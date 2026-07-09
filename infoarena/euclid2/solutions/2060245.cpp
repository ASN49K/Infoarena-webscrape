#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");

int divide(int a,int b)
{
    if(!b)
        return a;
    else
        return divide(b,a%b);
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
