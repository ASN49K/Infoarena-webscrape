#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int main (){
int a,b,c,i,n;
f>>n;
for (i=1;i<=n;i++) { f>>a>>b;
                     c=a%b;
                     while (c!=0) {a=b;b=c;c=a%b;}
                     g<<b<<"\n" ;  }

}
