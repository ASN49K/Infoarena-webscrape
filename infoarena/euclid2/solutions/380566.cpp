#include<iostream>
#include<math>
#include<fstream>
using namespace std;
int main()
{
long int a,b;
int n,r,i,c;
ifstream f;
ofstream ff;
f.open("euclid2.in");
ff.open("euclid2.out");
if( b<0) b=abs(b);
f>>n;
for(i=1;i<=n;i++)
 {
 f>>a;
 f>>b;
 while(a%b)
  {
  r=a%b;
  a=b;
  b=r;
  }
 ff<<b<<"\n";
 }
f.close();ff.close();
return 0;
}