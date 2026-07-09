#include <iostream>
#include <fstream>

using namespace std;
const int Nmax=2000000;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
int euclid(int a,int b)
{
    int c;
    while(b!=0)
    {
        c=a%b;
        a=b;
        b=c;
    }
    return a;
}
int main()
{
   int n,a,b;
   in>>n;
   for(int i=1;i<=n;i++)
   {
       in>>a>>b;
    out<<euclid(a,b);
    out<<'\n';
    }
}
