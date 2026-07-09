#include <iostream>
#include <fstream>
using namespace std;

/* Varianta scaderi repetate

int cmmdc(int a, int b)
{
   if(a==b)return a;
   if(a > b) return cmmdc(a-b, b);
         else return cmmdc(a, b-a);
}

*/
ifstream f("euclid2.in");
ofstream g("euclid2.out");

int cmmdc(int a, int b)
{
    int r = a%b;
    while(r!=0)
    {
       a = b;
       b = r;
       r = a%b;
    }
    return b;
}

int main()
{
   int a, b, n;

   f>>n;
   for(int i = 0; i < n; i++)
   {
      f>>a>>b;
      g<<cmmdc(a,b)<<'\n';
   }
}
