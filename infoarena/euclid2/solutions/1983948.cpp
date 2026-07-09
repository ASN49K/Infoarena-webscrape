#include <iostream>
#include <fstream>

using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");

int cmmdc(int a,int b)
  {
    if (b==0)  return a;
    return cmmdc(b,a%b);
  }

int main()
{
  int n;
  int a,b;
  in>>n;

  for(int i=1;i<=n;i++)
     {
     in>>a; in>>b;
     out<<cmmdc(a,b)<<"\n";
     }

   return 0;
}
