#include <iostream>
#include <fstream>
using namespace std;

 ifstream in("euclid2.in");
 ofstream out("euclid2.out");
int main()
{
    int a,b,t;
    in>>t;
    for(int i=1; i<=t; i++)
    {
        in>>a>>b;
        while(b!=0)
        {
            int r=a%b;
            a=b;
            b=r;
        }
        out<<a<<"\n";
    }

    return 0;
}
