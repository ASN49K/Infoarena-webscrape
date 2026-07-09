#include <iostream>
#include <fstream>
using namespace std;

int Euclid(int a, int b)
{
    if(b==0) return a;
    Euclid(b,a%b);
}

int main()
{
   ifstream f("euclid2.in");
   ofstream g("euclid2.out");

   long T;
   long long a,b;

   f>>T;

   for(long i=1; i<=T; i++)
   {
       f>>a>>b;
       g<<Euclid(a,b)<<endl;

   }

    return 0;
}
