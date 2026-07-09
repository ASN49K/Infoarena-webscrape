#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int a ,b;
int main()
{int i=0;
 f>>i;
 while(i)
   {

   int r=a%b;

    {a=b;
    b=r;
    r=a%b;

    }
    g<<b<<endl;
    i--;
   }
    return 0;
}
