#include<fstream>
using namespace std;
int main()
{int a,b,aux;
ifstream f("euclid2.in");
f>>a;f>>b; 
f.close();
while(a%b!=0)
{aux=a%b;
a=b;
b=aux;}
ofstream g("euclid2.out");
g<<b;
g.close();
return 0;
}
