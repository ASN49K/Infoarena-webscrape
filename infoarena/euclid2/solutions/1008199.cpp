#include <iostream>
#include<fstream>
using namespace std;

int main()
{ int a,b,n,i,x,aux;
 fstream f("euclid2.in",ios::in);
 fstream g("euclid2.out",ios::out);
 f>>n;
 for(i=1;i<=n;i++)
 { f>>a>>b;
   if(a<b) {aux=a;
            a=b;
            b=aux;}
   x=a%b;
   while(x){a=b;
            b=x;
            x=a%b;
             }

              g<<b<<" "<<endl;
 }
    return 0;
}
