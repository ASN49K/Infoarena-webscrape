#include <iostream>
#include <fstream>

using namespace std;
 ifstream fin ("euclid2.in");
 ofstream fout ("euclid2.out");

int main()
{ int t,a,i,r,b;
fin>>t;
for(i=1;i<=t;i++)
 {
     fin>>a;
     fin>>b;
     while(b)
     {
         r=a%b;
         a=b;
         b=r;
     }
     fout<<a<<"\n";

 }

    return 0;
}
