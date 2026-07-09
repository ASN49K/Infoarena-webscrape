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
f>>a>>b;
   int r=a%b;
while(r!=0)
    {a=b;
    b=r;
    r=a%b;

    }
    g<<b<<endl;
    i--;
   }
    return 0;
}
