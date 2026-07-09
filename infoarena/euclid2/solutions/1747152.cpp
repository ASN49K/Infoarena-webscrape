#include <iostream>
#include <fstream>
using namespace std;

/* Varianta 60 puncte



*/
ifstream f("euclid2.in");
ofstream g("euclid2.out");

int cmmdc(int a, int b)
{
   if(a==b)return a;
   if(a > b) return cmmdc(a-b, b);
         else return cmmdc(a, b-a);
}


int main()
{
   int a, b, n;

   f>>n;
   for(int i = 0; i < n; i++)
   {
      f>>a>>b;
      g<<cmmdc(a,b)<<endl;
   }
}
