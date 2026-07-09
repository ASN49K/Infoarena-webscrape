#include<iostream>
#include<fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
#define tip int
int euclid(int a, int b)
{
    int r;
    while(b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}

int main()
{
  int T;
  fin>>T;
  for(int i=0;i<T;i++)
  {
      int a, b;
      fin>>a;
      fin>>b;
      fout<<euclid(a,b)<<"\n";
  }




    return 0;
}
