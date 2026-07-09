#include <fstream>
using namespace std;

int main(){
ifstream f("euclid2.in");
ofstream g("euclid2.out");

int a,b,n,rest;

f >> n;

for (int c=0;c<n;c++)
     { f >> a;
       f >> b;
       while (b!=0)
              { rest=a%b;
                a=b;
                b=rest;
              }
       g << a << "\n";
     }





f.close();g.close();
return 0;
}
