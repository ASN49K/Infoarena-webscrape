#include <iostream>
#include<fstream>
using namespace std;
int cmmdc(int a, int b)
{
     while(a*b)
     {
         if(a>b)
            a=a%b;
         else b=b%a;
     }
     return a+b;
}
int main()
{ int n, a,b;
 ifstream f("euclid2.in");
 f>>n;
 ofstream g("euclid2.out");
 for(int i=0;i<n;i++)
 {
     f>>a>>b;
     g<<cmmdc(a,b)<<endl;
 }
 f.close();
 g.close();
 return 0;
}
