#include<iostream>
#include<fstream>
using namespace std;
int main()
{
   long long int t,i,a,b,z,s;
   ifstream f("euclid2.in");
   ofstream g("euclid2.out");
   f>>t;
   for(i=1;i<=t;i++)
   {
       f>>a;
       f>>b;
       for(s=1;s<=(a*b)/3;s++)
       {
           if((a%s==0)&&(b%s==0))
           {
             z=s;
           }
       }
       g<<z<<endl;
   }

   return 0;
}


