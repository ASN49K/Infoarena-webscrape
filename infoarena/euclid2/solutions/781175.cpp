#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int a,b,r,nr;
int main()
{
   fin>>nr;
  while(nr)
  {
    fin>>a>>b;
       while(b)
       {
           r=a%b;
           a=b;
           b=r;
       }
   fout<<a<<'\n';
   nr--;
  }

    return 0;
}
