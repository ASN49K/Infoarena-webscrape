#include <iostream>
#include <fstream>
using namespace std;
int div(int a,int b)
{
    if(b==0)
        return a;
    return div(b,a%b);
}


int main()
{
    ifstream f("euclid2.in");
ofstream g("euclid2.out");
int n,i,c,d;
   f>>n;
   for(i=1;i<=n;i++)
   {
       f>>c>>d;
      g<<div(c,d)<<endl;
   }
}
