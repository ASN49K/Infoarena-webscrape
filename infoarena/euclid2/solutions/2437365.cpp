#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream o("euclid2.out");
int n,M,K;
int CMMDC(int a,int b)
{   if(a==b)
    return a;
    if(a%b==0)
        return b;
    if(b%a==0)
        return a;
  if(a>b)
    return CMMDC(a%b,b);
  if(a<b)
    return CMMDC(a,b%a);

}
int main(){
f>>n;
for(int i=0;i<n;i++)
{
    f>>M;
    f>>K;
    o<<CMMDC(M,K)<<"\n";

}
return 0;
}
