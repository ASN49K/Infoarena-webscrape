#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
   int t,a,b,r;

   f>>t;
   for(int i=1;i<=t;i++) {
         f>>a;f>>b;   while(r){  r=a%b; a=b;b=r; }
            g<<b<<endl;
   }






    return 0;
}
