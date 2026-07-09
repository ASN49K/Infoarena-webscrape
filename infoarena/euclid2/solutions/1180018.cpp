#include<fstream>
#include<iostream>

using namespace std;

long long a,b,i,n,j,m;
int cmmdc(long long a, long long b);

int main()
{
    ifstream f("euclid2.in"); ofstream g("euclid2.out");
f>>n;

for(i=1;i<=n;i++)
 {
  f>>a>>b;
   g<<cmmdc(a,b)<<"\n";
 }
 
 f.close(); g.close();
}


int cmmdc(long long a, long long b)
{
long long r;
 r = 1;
 while(r)
  {
   r = a%b;
   a = b;
   b = r;
  }
 return a;
}
