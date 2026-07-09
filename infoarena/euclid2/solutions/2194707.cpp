#include <iostream>
#include <fstream>
using namespace std;
int t,a,b,i=1,d;
int main()
{
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");
    in>>t;
    while(i<=t)
    {
        in>>a>>b;
        while(b!=0)
        {
            d=a%b;
            a=b;
            b=d;
        }
        out<<a<<endl;
        i++;
    }
    return 0;
}
