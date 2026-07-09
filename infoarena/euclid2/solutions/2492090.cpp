#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
   long long t,i,a,b;
   fin>>t;
   for(i=1;i<=t;i++)
   {
       fin>>a>>b;
       while(a!=b)
       {
           if(a<b) b=b-a;
           else a=a-b;
       }
       fout<<a<<endl;
   }
}
