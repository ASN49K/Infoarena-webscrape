#include <fstream>

using namespace std;
int a,b,aux,t,i;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main()

{
    f>>t;
    for(i=1;i<=t;i++){
   f>>a>>b;
   while(b!=0)
   {
       aux=a; a=b; b=aux%b;

   }
  g<<a<<'\n';
}

    return 0;
}
