#include <fstream>
#include <iostream>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
int t,a,b;
int cmmdc(int a ,int b)
   {
    if(b==0)return a;
    else {
        return cmmdc(b,a%b);
        } }
int main()
{ in>>t;
for(int i=0;i<t;i++)
{in>>a>>b;
a=cmmdc(a,b);
out<<a<<"\n"; }
    return 0;
}
