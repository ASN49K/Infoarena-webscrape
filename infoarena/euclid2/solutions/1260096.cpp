#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

  int euclid(  int a,  int b){
    if(b==0)
        return a;
    else{
        return euclid(b,a%b);
    }
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
