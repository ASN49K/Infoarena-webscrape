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
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
   long long t,i,a,b,c;
   fin>>t;
   for(i=1;i<=t;i++)
   {
       fin>>a>>b;
       cmmdc(a,b);
   }
}
