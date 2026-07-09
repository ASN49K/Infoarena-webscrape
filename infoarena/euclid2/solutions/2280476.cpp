#include <fstream>
int i , t , a , r , b;
using namespace std;

ifstream f ("euclid2.in");
ofstream g ("euclid2.out");
int cmmdc (int a , int b )
{
    while(b)
       {
           r=a%b;
           a=b;
           b=r;
       }
    return a;
}
int main()
{
   f>>t;
   for(i=1;i<=t;i++)
   {
       f>>a>>b;
       g<<cmmdc(a,b)<<endl;
   }
}
