#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");

int divide(int a,int b)
{
    if(b==0)
        return a;
    else
        return divide(b,a%b);
}
int main()
{
     int c,d,aux,n;
     f>>n;
     for(int i=1;i<=n;i++)
     {
         f>>c>>d;
         if(c>d)
         {
             aux=c;
             c=d;
             d=aux;
         }
         g<<divide(c,d)<<endl;
     }
     f.close();
     g.close();
    return 0;
}
