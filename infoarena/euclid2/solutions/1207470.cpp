#include <fstream>

using namespace std;

int t,i,a,b,r;

int main()
{
   ifstream f("euclid2.in");
   ofstream g("euclid2.out");
   f>>t;
   for(i=1;i<=t;i++) {
    f>>a>>b;
    if(a==0) {
        r=a;
        a=b;
        b=r;
    }
    while(b>0) {
        r=a%b;
        a=b;
        b=r;
    }
    g<<a;
    g<<"\n";
   }
    return 0;
}
