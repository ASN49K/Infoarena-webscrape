#include <iostream>
#include <fstream>
using namespace std;
ofstream g ("euclid2.out");
long int a,b;
void euclid ()
{
   long int r;
   while(b)
   {
           r=a%b;
           a=b;
           b=r;
   }  
   g<<a<<"\n";
}
int main()
{
    long int t,i;
    ifstream f ("euclid2.in");
    f>>t;
    for(i=1;i<=t;i++)
    {
                     f>>a>>b;
                     euclid();
                     
    }
    f.close();
    g.close();
    return 0;
}
