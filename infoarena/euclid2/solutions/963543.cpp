#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int a,b,i,n,r;

int main()  {
   f>>n;
         for(i=1; i<=n; i++)  {
           f>>a>>b;
while(b)  {
r=a%b;
a=b;
b=r;
}

g<<a<<"\n";

}

f.close();
g.close();
return 0;
}
