#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
   int t,a,b,r,i;

   f>>t;
   for(i=1;i<=t;i++) {
         f>>a;f>>b;  r=a%b;  while(r){ a=b;b=r; r=a%b; }
            g<<b<<endl;
   }






    return 0;
}
