#include <iostream>
#include <fstream>
using namespace std;
int t,a,b,i,r;
int main()
{
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");
    in>>t;
    for(i=t;i>0;i--)
    {
        in>>a>>b;
        while(b)
        {
            r=b;
            b=a%b;
            a=r;
        }
        out<<a<<"\n";
    }
    return 0;
}
