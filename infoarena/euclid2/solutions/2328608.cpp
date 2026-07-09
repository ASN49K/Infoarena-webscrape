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
         a=b;
         b=c;
     }
     if(a==1)
        fout<<b<<endl;
     else fout<<a<<endl;
 }
 return 0;



}
