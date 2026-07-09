#include <fstream>
#include <iostream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int n;
int cmmdc(int x,int y){
while(x && y){
    if(x>y) x%=y;
    else y%=x;
}
if(x) return x;
return y;
}
int main()
{
   f>>n;
   for(int i=1;i<=n;i++)
   {
       int a,b;
       f>>a>>b;
       g<<cmmdc(a,b)<<endl;
   }
    return 0;
}
