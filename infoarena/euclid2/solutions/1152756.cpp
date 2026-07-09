#include <iostream>
#include <fstream>

using namespace std;

fstream f("cmmdc.in", ios::in);
fstream g("cmmdc.out", ios::out);

int c (int a, int b)
{
    while(a!=b)
      {

        if(a>b) a=a-b;
        else b=b-a;
      }
      return a;
}

int main()
{
    long long a,b;
    f >> a >> b;
   g << c(a,b);

return 0;
}
