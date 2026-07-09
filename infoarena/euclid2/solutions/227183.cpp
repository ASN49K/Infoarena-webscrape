#include <fstream>
using namespace std;
ifstream f1 ("euclid2.in");
ofstream f2 ("euclid2.out");
int main()
{
int n,a,b,i,r;
f1>>n;
 for(i=1;i<=n;++i)  
  {  f1>>a>>b;   
    while(a%b)   {r=a%b;   a=b;   b=r;}  
  f2<<b<<endl;}
f1.close();
f2.close();}
