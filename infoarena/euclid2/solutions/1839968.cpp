#include <iostream>
#include<fstream>
using namespace std;

int main()
{
    ifstream f1("euclid2.in");
    ofstream f2("euclid2.out");
    int t,a,b,r,i;
    f1>>t;
    for(i=1; i<=t; i++)
    {
        f1>>a>>b;
        if(a<b)
        {
            r=a;a=b;b=r;
        }
        r=a%b;
         while(r!=0)
         {
             a=b;
             b=r;
             r=a%b;
         }
        f2<<b<<endl;
    }
    f1.close();
    f2.close();
    return 0;
}
