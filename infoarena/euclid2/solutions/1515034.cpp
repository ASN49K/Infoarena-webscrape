#include<iostream>
#include<fstream>
using namespace std;
int cmmdc(int a, int b)
{
  if(b == 0)
    return a;
  else return cmmdc(b, a % b);
}
int main()
{int a, b, i;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
f>>i;
while(i != 0)
{f>>a>>b;
g<<cmmdc(a,b)<<"\n";
i--;
}
return 0;
}

