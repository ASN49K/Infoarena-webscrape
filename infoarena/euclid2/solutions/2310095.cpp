#include <iostream>
#include <fstream>
using namespace std;
int r,a,b,t,i;
int cmmdc(int a,int b)
{
      while(a!=b)
     {
       if(a>b)
            a=a-b;
       else
        b=b-a;
     }

    return a;

}
int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");

     f>>t;
     for(i=1;i<=t;i++)
    {f>>a>>b;
     g<<cmmdc(a,b)<<endl;}


    return 0;

}
