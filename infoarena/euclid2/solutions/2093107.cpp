#include<iostream>
#include<fstream>
using namespace std;
int cmmdc(int a,int b)
{while(b)
    {
       int r=a%b;
       a=b;
       b=r;

   }
   return a;
}
int main()
{
    ifstream f("euclid.txt");
   int n,a,b;
   f>>n;
   while(n)
   {f>>a>>b;
   cout<<cmmdc(a,b)<<endl;n--;}
   return 0;
}
