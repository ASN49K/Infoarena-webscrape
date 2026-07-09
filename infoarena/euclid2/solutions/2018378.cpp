#include <iostream>
#include <fstream>
using namespace std;
int t;
     ifstream in ("euclid2.in");
     ofstream out ("euclid2.out");
int euclid (int a, int b)
{

int c;
    while (b)
    {
        c=a%b;
        a=b;b=c;
    }
    return a;
}
 int main()
 {
     int a,b,i;
     in>>t;
     for (i=1;i<=t;i++)
     {
         in>>a>>b;
         out<<euclid(a,b)<<"\n";
     }

 }
