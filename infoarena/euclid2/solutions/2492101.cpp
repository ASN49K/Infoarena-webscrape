#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
   long long t,i,a,b,c;
   fin>>t;
   for(i=1;i<=t;i++)
   {
       fin>>a>>b;
       while(b!=0)
       {
           c=a%b;
           a=b;
           b=c;
       }
       fout<<a<<endl;
   }
}
