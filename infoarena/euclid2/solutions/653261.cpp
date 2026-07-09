#include <fstream>
using namespace std;
int cmmdc(int a, int b)
{int r;
do{
r=a%b;
a=b;
b=r;
}while(b);
return a;}
int main ()
{int n,k,rez;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
f>>n;
while(n)
{f>>rez>>k; n--;
g<<cmmdc(rez,k)<<'\n';
}

 g.close();
return 0;
}
