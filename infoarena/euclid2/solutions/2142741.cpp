#include<iostream>
#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
long long a,b,t,r,i;
int main()
{
   f>>t;
   for(i=1;i<=t;i++)
   {
       f>>a>>b;
       while(b)
       {
           r=a%b;
           a=b;
           b=r;
       }
       cout<<a<<endl;
   }
}
