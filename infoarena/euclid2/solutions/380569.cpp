#include<iostream.h>
#include<fstream.h>
//using namespace std;
int main()
{
long int a,b;
int n,r,i;
ifstream f;
ofstream ff;
f.open("euclid2.in");
ff.open("euclid2.out");
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
 if(b<0) b*=-1;
 ff<<b<<"\n";
 }
f.close();ff.close();
return 0;
}