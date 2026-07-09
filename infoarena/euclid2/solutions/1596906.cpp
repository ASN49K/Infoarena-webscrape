#include<fstream>
#include<iostream>
using namespace std;
int cmmdc(int a ,int b )
 { int r=0;
   while(b>0) {
    r=a%b;
    a=b;
    b=r;}
 return a ;
}

int main()
{
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int a,b,t,i;
f>>t;
for(i=1;i<=t;i++)
{
    f>>a>>b;
    g<<cmmdc(a,b)<<"\n";

}
return 0;
}
