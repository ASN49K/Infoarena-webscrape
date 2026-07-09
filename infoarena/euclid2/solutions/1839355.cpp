#include <iostream>
#include<fstream>
using namespace std;

int main()
{
    ifstream f1("euclid2.in");
    ofstream f2("euclid2.out");
    int t,a,b,r,d;
    f1>>t;
    for(int i=1; i<=t; i++)
    {
        f1>>a>>b;
        if(a*b==0)
            d=a+b;
        else
        {
            r=a%b;
         while(r!=0)
         {
             a=b;
             b=r;
             r=a%b;
         }
         d=b;
        }

        f2<<d<<endl;
    }
    f1.close();
    f2.close();
    return 0;
}
