#include <iostream>
#include <fstream>
using namespace std;
ifstream f("cmmdc.in");
ofstream g("cmmdc.out");
int main()
{int a,b,aux;
 f>>a>>b;

 while(b>0)
 {aux=a%b;
  a=b;  b=aux;
 }
 if(a==1)  g<<0;
else g<<a;









    return 0;
}
