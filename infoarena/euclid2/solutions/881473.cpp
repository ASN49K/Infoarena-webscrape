#include <iostream>
#include <fstream>
using namespace std;

int cmmdc(int a,int b)
{
   int rest;
   while(b)
   {
       rest=a%b;
       a=b;
       b=rest;
   }
   return a;
}

int main()
{
    int n;
    long int a,b;
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");
    in>>n;
    for(int i=1;i<=n;++i)
    {
        in>>a>>b;
        out<<cmmdc(a,b)<<"\n";
    }
    return 0;
}
