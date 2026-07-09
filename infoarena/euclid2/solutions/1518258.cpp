#include <iostream>
#include <fstream>
using namespace std;

int T,a,b ;
int f(int a, int b)
{
    if(!b) return a;
    return f(b, a%b);
}

int main()
{
   ifstream fin("euclid2.in");
   ofstream fout ("euclid2.out");
   fin>>T;
   for(int i=1; i<=T; i++);
      {
          fin>>a>>b;
          fout<<f(a,b)<<'\n';

      }
    return 0;
}
