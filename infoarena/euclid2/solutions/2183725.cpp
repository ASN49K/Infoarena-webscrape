#include <iostream>
#include <fstream>
using namespace std;
void schimb(int &a,int &b)
{
    int c=a;
    a=b;
    b=c;
}
int cmmdc(int a,int b)
{
    if(a<b)
     schimb(a,b);

    int m;
    while(b!=0)
    {
       m=a%b;
       a=b;
       b=m;
    }
  return a;
}
int main()
{
   int T,a,b;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
f>>T;
while(!f.eof())
{
    f>>a>>b;
    g<<cmmdc(a,b)<<endl;
}
f.close();
    return 0;
}
