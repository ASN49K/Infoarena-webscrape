#include <iostream>
#include <fstream>

using namespace std;

int cmmdc(int a,int b)
{
  if(a==0)
    return b;
  if(b==0)
    return a;
  if(a%2==0&&b%2==0)
    return 2*cmmdc(a/2,b/2);
  if(a%2==0&&b%2)
    return cmmdc(a/2,b);
  if(a%2&&b%2==0)
    return cmmdc(a,b/2);
  if(a>b)
    return cmmdc(b,a-b);
  return cmmdc(a,b-a);
}

void fct()
{
  int a,b,n;
  ifstream fin("euclid2.in");
  ofstream fout("euclid2.out");
  fin>>n;
  for(int i=0;i<n;i++)
  {
    fin>>a>>b;
    fout<<cmmdc(a,b)<<"\n";
  }
}

int main()
{
    fct();
    return 0;
}
