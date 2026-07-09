#include <iostream>
#include <fstream>
using namespace std;
int cmmdc(int a, int b)
{
    if(b==0) return a;
    else return cmmdc(b,a%b);
}
int main()
{
    ifstream fin("cmmdc.in");
    ofstream fout("cmmdc.out");
   long long t,i,a,b;
   fin>>t;
   for(i=1;i<=t;i++)
   {
       fin>>a>>b;
       fout<<cmmdc(a,b)<<endl;
   }
}
