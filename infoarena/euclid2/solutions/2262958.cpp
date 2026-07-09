#include <iostream>
#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int Alg(int x,int y,int t)
{
   if(x==0)
   return t;
   else
   {
       t=x;
       return Alg(y%x,t,x);
   }
}

int main()
{int n,i=0,a,b,t;
f>>n;
while(i!=n)
{
    i++;
    f>>a>>b;
    t=0;
    g<<Alg(a,b,t)<<endl;

}

    return 0;
}
