#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("flip.in");
ofstream fout("flip.out");
long n,m;
int main ()
{
 fin>>n;
 for(int i=1;i<=n;i++)
 {

     int a,b;
     fin>>a>>b;
     int c;
     while(b!=0)
     {
         c=a%b;
         a=c;
         b=a;
     }
     if(a!=0)
        fout<<a<<endl;
     else fout<<b<<endl;
 }
 return 0;



}
