#include <fstream>

using namespace std;
int a,b,aux;
ifstream f("cmmdc.in");
ofstream g("cmmdc.out");
int main()

{

   f>>a>>b;
   while(b!=0)
   {
       aux=a; a=b; b=aux%b;

   } if(a==1)
   g<<0;
   else

  g<<a;

    return 0;
}
