#include<iostream>
#include<fstream>
using namespace std;
int main()
{
  ifstream f("euclid2.in");
  ofstream g("euclid2.out");
  unsigned int T;
  unsigned long int a,b;
  f>>T;
  for(int i=1;i<=T;i++)
  {
    f>>a;
    f>>b;
    while(a!=b)
    {
      if(a>b) a=a-b;
      else b=b-a;
    }
    g<<a<<endl;
  }
  return 0;
}
