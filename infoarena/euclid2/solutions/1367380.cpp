#include <iostream>
#include <fstream>
using namespace std;
#define ull unsigned long long int
#define m 666013
ifstream in("euclid2.in");
ofstream out("euclid.out");
int main()
{
   int i,n,t,a,b,r;
   in>>t;
   for(i=0;i<t;i++)
   {
       in>>a>>b;
       while(b)
       {
           r = a%b;
           a = b;
           b = r;
       }
       out<<a<<"\n";
   }
}
