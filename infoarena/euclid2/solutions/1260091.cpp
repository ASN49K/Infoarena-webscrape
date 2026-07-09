#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

  int euclid(  int a,  int b){
    if(b==0)
        return a;
    if(a==0)
        return b;
    if(a>b)
        return euclid(a%b,b);
    if(a<b)
        return euclid(a,b%a);

}

int main()
{
   ifstream f("euclid2.in",ios::in);
   ofstream g("euclid2.out",ios::out);
     int t;
   f>>t;

   while(t){
        int a,b;
        f>>a>>b;
        g<<euclid(a,b)<<endl;
        t--;
   }
   f.close();
   g.close();
   return 0;




}
