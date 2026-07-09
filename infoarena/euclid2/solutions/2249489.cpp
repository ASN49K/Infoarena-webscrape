#include <iostream>
#include <fstream>


using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");



int main()

{
    int a,b,t,n;
    f>>n;
   while(n)
{
    f>>a>>b;
    n--;


   while(b)
   {
       t=b;
       b=a%b;
       a=t;


   }
        g<<a<<endl;


}


}
