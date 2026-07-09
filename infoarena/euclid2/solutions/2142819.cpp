#include<iostream>
#include<fstream>
using namespace std;
int cmmdc (int a,int b)
{
    if(b==0)return a;
    else cmmdc(b,a%b);
}
int main()
{
ifstream f("euclid2.in");
ofstream g("euclid2.out");
   int a,b,t,r,i;
   f>>t;
   for(i=1;i<=t;i++)
   {
       f>>a>>b;
       g<<cmmdc(a,b)<<endl;
   }
}
