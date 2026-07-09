#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream o("euclid2.out");
int n,M,K;
int CMMDC(int a,int b)
{
   int x=a;
   int y=b;
   if(x>y)
   {
       for(int j=x/2;j>0;j--)
       {
           if(x%j==0 && y%j==0)
            return j;
       }
   }
   if(x==y)
    return x;
   if(x<y)
   {
       for(int j=y/2;j>0;j--)
       {
           if(x%j==0 && y%j==0)
            return j;
       }
   }
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
