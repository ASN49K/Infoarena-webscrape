#include <fstream>
using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

void exec(long a,long b) {
  while (a!=b)
    if (a>b) a=a-b;
        else b=b-a;

    g<<a<<"\n";
}

int main()
 {
     long t,a,b;
     f>>t;
     for (long i=1;i<=t;i++)
     {
         f>>a;
         f>>b;
         exec(a,b);
     }

 }
