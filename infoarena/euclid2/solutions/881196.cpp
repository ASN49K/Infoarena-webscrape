#include <fstream>
using namespace std;
ifstream f("algoritm.in"); 
ofstream g("algoritm.out");
int a,b,i,n,r;
int main()
{ f>>n;
for(i=1; i<=n; i++)
{ f>>a>>b;
while(b)
{ r=a%b;
a=b;
b=r;
}
g<<a<<"\n";
}
g.close(); return 0;
}
