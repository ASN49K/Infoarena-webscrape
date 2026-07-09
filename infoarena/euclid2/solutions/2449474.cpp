#include <iostream>

using namespace std;

int main()
{
   int a, b, cmmdc, cmmmc;
   cin >> a >> b; cmmmc = a*b;
   while (a!=b)
   {
       if(a> b)
        a-=b;
       else
        b-=a;
   }
   cmmdc = a;
   cmmmc/=a;
   cout << cmmdc << " "<< cmmmc;
    return 0;
}
