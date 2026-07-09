#include <fstream>

using namespace std;

int main()
{  int a,b,aux,i,z,r,c;
   fstream f1("euclid2.in",ios::in);
   fstream f2("euclid2.out",ios::out);
   f1>>z;

   for(i=0;i<z;i++)
    {   f1>>a;
        f1>>b;
        if(b>a)
        {aux=a;a=b;b=aux;}
        while(b!=0)
     {
       r=a%b;
       a=b;
       b=r;
      }
     a=c;
    f2<<c;
   }

   f1.close();f2.close();

    return 0;
}
