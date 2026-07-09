#include <iostream>
#include <fstream>

using namespace std;
ifstream f("cmmdc.in");
ofstream g("cmmdc.out");
unsigned int a,b;
int cmmdc (int a,int b)
{
 while (a!=b)
  if (a>b)
   a=a-b;
  else
   b=b-a;
 return a;
}
int main()
{f>>a>>b;
cmmdc(a,b);
if(a%b!=0||b%a!=0) g<<0;
else g<<cmmdc(a,b);
return 0;

}
