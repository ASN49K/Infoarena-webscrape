#include <iostream>
#include <fstream>
using namespace std;
ifstream f ("euclid2.in");
ofstream g ("euclid2.out");

int a,b,i,c,n;
int main()

{
     f>>n;

     for(i=1;i<=n;i++)
        {
         f>>a>>b;
    if(a+1!=b||a-1!=b)
        while (b!=0)
            {
            c = a % b;
            a = b;
            b = c;
            }
          g<<a<<'\n';


         }
}
